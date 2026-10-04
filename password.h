#ifndef password_H
#define password_H

#include <string>
#include <vector>

using namespace std;

class User
{
private:
    string name;
    string username;
    string password;

public:
    User();
    User(string name, string username, string password);

    string getName() const;
    string getUsername() const;
    string getPassword() const;

    void setName(string name);
    void setUsername(string username);
    void setPassword(string password);
};

bool usernameExists(const vector<User>& users, const string& username);

void registerUser(vector<User>& users);

bool loginUser(const vector<User>& users, string& loggedInUsername);

string generatePassword(int length);

string createManualPassword();

string createPassword();

string checkPasswordStrength(const string& password);

void displayPasswordStrength(const string& password);

int chooseService();

void runPasswordModule(vector<User>& users);

#endif
