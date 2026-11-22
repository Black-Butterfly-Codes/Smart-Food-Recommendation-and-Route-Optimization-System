#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>

namespace InputValidation
{
    // Reads an integer within the specified range.
    // Returns false if the input stream reaches EOF.
    bool readIntInRange(
        const std::string& prompt,
        int minimum,
        int maximum,
        int& result
    );

}

#endif
