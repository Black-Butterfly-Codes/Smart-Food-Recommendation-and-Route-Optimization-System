#include <iostream>
#include "password.h"
#include "data.h"
#include "dining.h"

using namespace std;

int main()
{
    vector<User> users;

    int serviceChoice =
        runPasswordModule(users);

    if (serviceChoice == 1)
    {
        runDiningModule();
    }
    else if (serviceChoice == 2)
    {
        cout << "\nTakeaway module coming soon." << endl;
    }
    else if (serviceChoice == 3)
    {
        cout << "\nDrive-through module coming soon." << endl;
    }

    return 0;
}
