#include <iostream>
#include <vector>

#include "password.h"
#include "data.h"
#include "dining.h"
#include "takeaway.h"
#include "drive.h"

using namespace std;

int main()
{
    vector<User> users;

    int choice = runPasswordModule(users);

    if (choice == 1)
    {
        runDiningModule();
    }
    else if (choice == 2)
    {
        runTakeawayModule();
    }
    else if (choice == 3)
    {
        runDriveModule();
    }
    else
    {
        cout << "\nInvalid service selection or login unsuccessful.\n";
    }

    return 0;
}
