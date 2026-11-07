#include "file_manager.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace FileManager
{

    // Check whether a file exists
    bool fileExists(const string& filename)
    {
        ifstream file(filename.c_str());

        return file.good();
    }


    // Create a file if it does not exist
    bool createFile(const string& filename)
    {
        if (fileExists(filename))
        {
            return true;
        }

        ofstream file(filename.c_str());

        if (!file)
        {
            return false;
        }

        file.close();

        return true;
    }


    // Write data into a file
    bool writeFile(
        const string& filename,
        const vector<string>& records)
    {
        ofstream file(filename.c_str());

        if (!file)
        {
            return false;
        }

        for (const string& record : records)
        {
            file << record << endl;
        }

        file.close();

        return true;
    }


    // Append a new record
    bool appendRecord(
        const string& filename,
        const string& record)
    {
        ofstream file(filename.c_str(), ios::app);

        if (!file)
        {
            return false;
        }

        file << record << endl;

        file.close();

        return true;
    }


    // Read all records from a file
    vector<string> readFile(const string& filename)
    {
        vector<string> records;

        ifstream file(filename.c_str());

        if (!file)
        {
            return records;
        }

        string line;

        while (getline(file, line))
        {
            if (!line.empty())
            {
                records.push_back(line);
            }
        }

        file.close();

        return records;
    }

}