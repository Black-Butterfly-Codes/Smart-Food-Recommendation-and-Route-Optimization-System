#include <iostream>
#include <windows.h>
#include <bcrypt.h>

using namespace std;

int main()
{
    BCRYPT_ALG_HANDLE algorithm = NULL;

    NTSTATUS status = BCryptOpenAlgorithmProvider(
        &algorithm,
        BCRYPT_SHA256_ALGORITHM,
        NULL,
        BCRYPT_ALG_HANDLE_HMAC_FLAG
    );

    if (status != 0)
    {
        cout << "SHA-256 initialization failed." << endl;
        return 1;
    }

    unsigned char password[] = "SmartBiteTest";
    unsigned char salt[] = "TestSalt12345678";
    unsigned char hash[32];

    status = BCryptDeriveKeyPBKDF2(
        algorithm,
        password,
        sizeof(password) - 1,
        salt,
        sizeof(salt) - 1,
        100000,
        hash,
        sizeof(hash),
        0
    );

    BCryptCloseAlgorithmProvider(algorithm, 0);

    if (status == 0)
        cout << "PBKDF2-SHA256: WORKING" << endl;
    else
        cout << "PBKDF2-SHA256: FAILED" << endl;

    return status == 0 ? 0 : 1;
}
