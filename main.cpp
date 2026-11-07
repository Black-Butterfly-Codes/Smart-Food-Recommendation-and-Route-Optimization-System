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

    int serviceChoice = runPasswordModule(users);

    if (serviceChoice == 1)
    {
        runDiningModule();
    }
    else if (serviceChoice == 2)
    {
        runTakeawayModule();
    }
    else if (serviceChoice == 3)
    {
        runDriveModule();
    }

    return 0;
}
