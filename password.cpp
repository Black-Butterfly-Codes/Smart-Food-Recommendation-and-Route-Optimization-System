#include "password.h"
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;
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

void runPasswordModule(vector<User>& users)
{
    int choice;
    bool loginSuccess = false;

    cout << "===== REGISTRATION & PASSWORD =====" << endl;
    cout << "1. New User" << endl;
    cout << "2. Existing User" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        registerUser(users);
        loginSuccess = true;
    }
    else if (choice == 2)
    {
        string loggedInUsername;
        loginSuccess = loginUser(users, loggedInUsername);
    }
    else
    {
        cout << "Invalid choice." << endl;
        return;
    }

    if (loginSuccess)
    {
        chooseService();
    }
}

void registerUser(vector<User>& users)
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
        return;
    }

    string password = createPassword();

    User newUser(name, username, password);
    users.push_back(newUser);

    cout << "\nAccount created successfully." << endl;
}



bool usernameExists(const vector<User>& users, const string& username)
{
    for (const User& user : users)
    {
        if (user.getUsername() == username)
        {
            return true;
        }
    }

    return false;
}


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

        return generatePassword(length);
    }
    else if (choice == 2)
    {
        return createManualPassword();
    }
    else
    {
        cout << "Invalid choice." << endl;
        return "";
    }
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

    return password;
}



string checkPasswordStrength(const string& password)
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char ch : password)
    {
        if (isupper(ch))
            hasUpper = true;
        else if (islower(ch))
            hasLower = true;
        else if (isdigit(ch))
            hasDigit = true;
        else
            hasSpecial = true;
    }

    int score = 0;

    if (password.length() >= 8)
        score++;

    if (hasUpper)
        score++;

    if (hasLower)
        score++;

    if (hasDigit)
        score++;

    if (hasSpecial)
        score++;

    if (score <= 2)
        return "Weak";
    else if (score <= 4)
        return "Moderate";
    else
        return "Strong";
}


void displayPasswordStrength(const string& password)
{
    string strength = checkPasswordStrength(password);

    cout << "Password Strength: " << strength << endl;
}


bool loginUser(const vector<User>& users, string& loggedInUsername)
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
            user.getPassword() == password)
        {
            loggedInUsername = username;

            cout << "\nLogin successful." << endl;
            cout << "Welcome back, " << user.getName() << "!" << endl;

            return true;
        }
    }

    cout << "\nInvalid username or password." << endl;

    return false;
}


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
    {
        return choice;
    }

    cout << "Invalid choice." << endl;
    return 0;
}



