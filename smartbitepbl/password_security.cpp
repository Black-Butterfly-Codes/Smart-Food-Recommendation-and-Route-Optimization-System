
#include "password_security.h"

#include <windows.h>
#include <bcrypt.h>
#include <cstdio>
#include <string>

using namespace std;

const ULONG ITERATIONS = 100000;
const int SALT_SIZE = 16;
const int HASH_SIZE = 32;

string toHex(const unsigned char* data, int length)
{
    const char digits[] = "0123456789abcdef";
    string result;

    for (int i = 0; i < length; i++)
    {
        result += digits[data[i] >> 4];
        result += digits[data[i] & 0x0F];
    }

    return result;
}

bool fromHex(const string& input,
             unsigned char* output,
             int length)
{
    if (input.length() != static_cast<size_t>(length * 2))
        return false;

    for (int i = 0; i < length; i++)
    {
        unsigned int value;

        if (sscanf(input.substr(i * 2, 2).c_str(),
                   "%2x", &value) != 1)
            return false;

        output[i] = static_cast<unsigned char>(value);
    }

    return true;
}

bool deriveHash(const string& password,
                const unsigned char* salt,
                unsigned char* hash)
{
    BCRYPT_ALG_HANDLE algorithm = NULL;

    NTSTATUS status = BCryptOpenAlgorithmProvider(
        &algorithm,
        BCRYPT_SHA256_ALGORITHM,
        NULL,
        BCRYPT_ALG_HANDLE_HMAC_FLAG
    );

    if (status != 0)
        return false;

    status = BCryptDeriveKeyPBKDF2(
        algorithm,
        reinterpret_cast<PUCHAR>(
            const_cast<char*>(password.data())),
        static_cast<ULONG>(password.length()),
        const_cast<PUCHAR>(salt),
        SALT_SIZE,
        ITERATIONS,
        hash,
        HASH_SIZE,
        0
    );

    BCryptCloseAlgorithmProvider(algorithm, 0);

    return status == 0;
}

bool hashPassword(const string& password,
                  string& storedHash)
{
    if (password.empty())
        return false;

    unsigned char salt[SALT_SIZE];
    unsigned char hash[HASH_SIZE];

    NTSTATUS status = BCryptGenRandom(
        NULL,
        salt,
        SALT_SIZE,
        BCRYPT_USE_SYSTEM_PREFERRED_RNG
    );

    if (status != 0 || !deriveHash(password, salt, hash))
        return false;

    storedHash = toHex(salt, SALT_SIZE) + ":" +
                 toHex(hash, HASH_SIZE);

    return true;
}

bool verifyPassword(const string& password,
                    const string& storedHash)
{
    size_t separator = storedHash.find(':');

    if (separator == string::npos)
        return false;

    unsigned char salt[SALT_SIZE];
    unsigned char originalHash[HASH_SIZE];
    unsigned char calculatedHash[HASH_SIZE];

    if (!fromHex(storedHash.substr(0, separator),
                 salt, SALT_SIZE))
        return false;

    if (!fromHex(storedHash.substr(separator + 1),
                 originalHash, HASH_SIZE))
        return false;

    if (!deriveHash(password, salt, calculatedHash))
        return false;

    unsigned char difference = 0;

    for (int i = 0; i < HASH_SIZE; i++)
        difference |= originalHash[i] ^ calculatedHash[i];

    return difference == 0;
}
