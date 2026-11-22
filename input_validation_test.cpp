#include <iostream>
#include "utilities/input_validation.h"

using namespace std;

int main()
{
    int choice;

    cout << "========== INPUT VALIDATION TEST ==========\n";

    if (!InputValidation::readIntInRange(
            "Enter a number between 1 and 3: ",
            1,
            3,
            choice))
    {
        return 0;
    }

    cout << "\nAccepted value: " << choice << endl;

    return 0;
}
