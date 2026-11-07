#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

using namespace std;

namespace FileManager
{
    // Check whether a file exists
    bool fileExists(const string& filename);

    // Create a file if it does not exist
    bool createFile(const string& filename);

    // Write data into a file
    bool writeFile(const string& filename,
                   const vector<string>& records);

    // Append a new record
    bool appendRecord(const string& filename,
                      const string& record);

    // Read all records from a file
    vector<string> readFile(const string& filename);
}

#endif