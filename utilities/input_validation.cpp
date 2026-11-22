#include "input_validation.h"

#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

namespace InputValidation
{
    bool readIntInRange(
        const string& prompt,
        int minimum,
        int maximum,
        int& result
    )
    {
        if (minimum > maximum)
        {
            cerr << "[ERROR] Invalid validation range." << endl;
            return false;
        }

        string input;

        while (true)
        {
            cout << prompt;

            // Read the entire line.
            // This also handles leftover newlines from previous cin operations.
            if (!getline(cin >> ws, input))
            {
                cout << "\n[INFO] Input stream closed." << endl;
                return false;
            }

            stringstream parser(input);

            int value;
            char extraCharacter;

            // Reject empty input, non-numeric input,
            // and input containing extra characters.
            if (!(parser >> value) || (parser >> extraCharacter))
            {
                cout << "[ERROR] Please enter a valid whole number."
                     << endl;
                continue;
            }

            // Validate the allowed range.
            if (value < minimum || value > maximum)
            {
                cout << "[ERROR] Please enter a number between "
                     << minimum << " and " << maximum << "."
                     << endl;
                continue;
            }

            result = value;
            return true;
        }
    }
}
