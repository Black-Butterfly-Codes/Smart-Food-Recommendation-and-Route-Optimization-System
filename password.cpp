#include "password.h"
#include "password_security.h"
#include "filehandling/file_manager.h"

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

const string USER_FILE = "data/users.txt";

// ================= USER CLASS =================

User::User()
{
}

User::User(string name, string username, string password)
{
    this->name = name;
    this->username = username;
    this->password = password;
}

string User::getName() const
{
    return name;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

void User::setName(string name)
{
    this->name = name;
}

void User::setUsername(string username)
{
    this->username = username;
}

void User::setPassword(string password)
{
    this->password = password;
}

// ================= LOAD USERS =================

bool loadUsers(vector<User>& users)
{
    users.clear();

    if (!fm::ensureFileExists(USER_FILE))
    {
        cout << "Unable to create user data file." << endl;
        return false;
    }

    vector<string> records;

    if (!fm::readAllRecords(USER_FILE, records))
    {
        cout << "Unable to load user accounts." << endl;
        return false;
    }

    for (const string& record : records)
    {
        vector<string> fields = fm::parseRecord(record);

        if (fields.size() != 3)
            continue;

        User user(fields[0], fields[1], fields[2]);
        users.push_back(user);
    }

    cout << "Saved accounts loaded: " << users.size() << endl;

    return true;
}

// ================= REGISTRATION =================

bool usernameExists(
    const vector<User>& users,
    const string& username)
{
    for (const User& user : users)
    {
        if (user.getUsername() == username)
            return true;
    }

    return false;
}

bool registerUser(vector<User>& users)
{
    string name;
    string username;

    cout << "\n===== CREATE NEW ACCOUNT =====" << endl;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(users, username))
    {
        cout << "Username already exists." << endl;
        return false;
    }

    string password = createPassword();

    if (password.empty())
    {
        cout << "Password creation failed." << endl;
        return false;
    }

    string storedHash;

    if (!hashPassword(password, storedHash))
    {
        cout << "Password security operation failed." << endl;
        return false;
    }

    vector<string> fields;

    fields.push_back(name);
    fields.push_back(username);
    fields.push_back(storedHash);

    if (!fm::appendRecord(USER_FILE, fields))
    {
        cout << "Unable to save account." << endl;
        return false;
    }

    User newUser(name, username, storedHash);
    users.push_back(newUser);

    cout << "\nAccount created and saved successfully." << endl;

    return true;
}

// ================= PASSWORD CREATION =================

string createPassword()
{
    int choice;

    cout << "\n===== CREATE PASSWORD =====" << endl;
    cout << "1. Automatic Password" << endl;
    cout << "2. Manual Password" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int length;

        cout << "Enter password length: ";
        cin >> length;

        if (length < 8 || length > 128)
        {
            cout << "Password length must be between 8 and 128."
                 << endl;
            return "";
        }

        return generatePassword(length);
    }
    else if (choice == 2)
    {
        return createManualPassword();
    }

    cout << "Invalid choice." << endl;
    return "";
}

string generatePassword(int length)
{
    string characters =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "!@#$%^&*()-_=+[]{};:,.<>?/";

    string password = "";

    for (int i = 0; i < length; i++)
    {
        int index = rand() % characters.length();
        password += characters[index];
    }

    cout << "Generated Password: " << password << endl;

    return password;
}

string createManualPassword()
{
    string password;

    cout << "Enter your password: ";
    cin >> password;

    displayPasswordStrength(password);

    if (password.length() < 8)
    {
        cout << "Password must contain at least 8 characters."
             << endl;
        return "";
    }

    return password;
}

// ================= PASSWORD STRENGTH =================

string checkPasswordStrength(const string& password)
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char ch : password)
    {
        unsigned char c = static_cast<unsigned char>(ch);

        if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (isdigit(c))
            hasDigit = true;
        else
            hasSpecial = true;
    }

    int score = 0;

    if (password.length() >= 8) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    if (score <= 2)
        return "Weak";
    else if (score <= 4)
        return "Moderate";

    return "Strong";
}

void displayPasswordStrength(const string& password)
{
    cout << "Password Strength: "
         << checkPasswordStrength(password) << endl;
}

// ================= LOGIN =================

bool loginUser(
    const vector<User>& users,
    string& loggedInUsername)
{
    string username;
    string password;

    cout << "\n===== LOGIN =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (const User& user : users)
    {
        if (user.getUsername() == username &&
            verifyPassword(password, user.getPassword()))
        {
            loggedInUsername = username;

            cout << "\nLogin successful." << endl;
            cout << "Welcome back, "
                 << user.getName() << "!" << endl;

            return true;
        }
    }

    cout << "\nInvalid username or password." << endl;

    return false;
}

// ================= SERVICE SELECTION =================

int chooseService()
{
    int choice;

    cout << "\n===== WHAT BRINGS YOU TODAY? =====" << endl;
    cout << "1. Dining" << endl;
    cout << "2. Takeaway" << endl;
    cout << "3. Drive-through" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    if (choice >= 1 && choice <= 3)
        return choice;

    cout << "Invalid choice." << endl;

    return 0;
}

// ================= MAIN PASSWORD MODULE =================

int runPasswordModule(vector<User>& users)
{
    if (!loadUsers(users))
        return 0;

    int choice;
    bool loginSuccess = false;

    cout << "\n==== REGISTRATION & PASSWORD ====" << endl;
    cout << "1. New User" << endl;
    cout << "2. Existing User" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    if (choice == 1)
    {
        loginSuccess = registerUser(users);
    }
    else if (choice == 2)
    {
        string loggedInUsername;

        loginSuccess = loginUser(users, loggedInUsername);
    }
    else
    {
        cout << "Invalid choice." << endl;
        return 0;
    }

    if (loginSuccess)
        return chooseService();

    return 0;
}
