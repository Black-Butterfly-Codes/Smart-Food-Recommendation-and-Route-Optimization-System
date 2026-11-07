#include "file_manager.h"

#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

namespace fm
{
  
    static string sanitizeField(const string& field)
    {
        string clean = field;

        for (size_t i = 0; i < clean.size(); i++)
        {
            if (clean[i] == '|' ||
                clean[i] == '\n' ||
                clean[i] == '\r')
            {
                clean[i] = ' ';
            }
        }

        return clean;
    }

    static bool isBlankLine(const string& line)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ' &&
                line[i] != '\t' &&
                line[i] != '\r')
            {
                return false;
            }
        }

        return true;
    }

    // Save updated records safely using temporary and backup files.
    static bool writeTempAndReplace(
        const string& filePath,
        const vector<string>& records)
    {
        string tempPath = filePath + ".tmp";
        string backupPath = filePath + ".bak";

        if (!writeAllRecords(tempPath, records))
            return false;

        // Preserve the original file before replacing it.
        if (rename(filePath.c_str(), backupPath.c_str()) != 0)
        {
            remove(tempPath.c_str());
            cout << "[File Error] Could not create backup." << endl;
            return false;
        }

        if (rename(tempPath.c_str(), filePath.c_str()) != 0)
        {
            // Restore the original file if replacement fails.
            rename(backupPath.c_str(), filePath.c_str());
            remove(tempPath.c_str());

            cout << "[File Error] Replacement failed." << endl;
            return false;
        }

        // Replacement succeeded; remove the backup.
        remove(backupPath.c_str());

        return true;
    }

    // Convert fields into one line separated by '|'.
    string encodeRecord(const vector<string>& fields)
    {
        string line;

        for (size_t i = 0; i < fields.size(); i++)
        {
            if (i > 0)
                line += "|";

            line += sanitizeField(fields[i]);
        }

        return line;
    }
    vector<string> parseRecord(const string& line)
    {
        vector<string> fields;
        string current;

        for (size_t i = 0; i < line.size(); i++)
        {
            char c = line[i];

            if (c == '\r')
                continue;

            if (c == '|')
            {
                fields.push_back(current);
                current.clear();
            }
            else
            {
                current += c;
            }
        }

        fields.push_back(current);

        return fields;
    }
    bool fileExists(const string& filePath)
    {
        ifstream file(filePath.c_str());
        return file.good();
    }

    // Create a file if it does not exist.
    bool ensureFileExists(const string& filePath)
    {
        if (fileExists(filePath))
            return true;

        ofstream file(filePath.c_str());

        if (!file.is_open())
            return false;

        file.close();

        return !file.fail();
    }

    // Write all records, replacing existing contents.
    bool writeAllRecords(
        const string& filePath,
        const vector<string>& records)
    {
        ofstream file(filePath.c_str(), ios::trunc);

        if (!file.is_open())
        {
            cout << "[File Error] Cannot open file for writing."
                 << endl;
            return false;
        }

        for (size_t i = 0; i < records.size(); i++)
        {
            file << records[i] << '\n';

            if (!file.good())
            {
                file.close();
                return false;
            }
        }

        file.close();

        return !file.fail();
    }

    // Read all records from a file.
    // Read all records from a file.
bool readAllRecords(
    const string& filePath,
    vector<string>& records)
{
    records.clear();

    ifstream file(filePath.c_str());

    if (!file.is_open())
    {
        cout << "[File Error] Cannot open file for reading."
             << endl;
        return false;
    }

    string line;

    while (getline(file, line))
    {
        if (!isBlankLine(line))
        {
            records.push_back(line);
        }
    }

    bool ok = !file.bad();

    file.close();

    return ok;
}

    // Add a new record.
    bool appendRecord(
        const string& filePath,
        const vector<string>& fields)
    {
        if (!ensureFileExists(filePath))
        {
            cout << "[File Error] Cannot create file." << endl;
            return false;
        }

        ofstream file(filePath.c_str(), ios::app);

        if (!file.is_open())
            return false;

        file << encodeRecord(fields) << '\n';

        bool ok = file.good();

        file.close();

        return ok && !file.fail();
    }

    // Update a record using a selected key field.
    bool updateRecord(
        const string& filePath,
        int keyFieldIndex,
        const string& keyValue,
        const vector<string>& newFields)
    {
        if (keyFieldIndex < 0)
            return false;

        vector<string> records;

        if (!readAllRecords(filePath, records))
            return false;

        bool found = false;

        for (size_t i = 0; i < records.size(); i++)
        {
            vector<string> fields = parseRecord(records[i]);

            if (keyFieldIndex < static_cast<int>(fields.size()) &&
                fields[keyFieldIndex] == keyValue)
            {
                records[i] = encodeRecord(newFields);
                found = true;
            }
        }

        if (!found)
        {
            cout << "[File] Record not found." << endl;
            return false;
        }

        return writeTempAndReplace(filePath, records);
    }

    // Delete records matching the selected key.
    bool deleteRecord(
        const string& filePath,
        int keyFieldIndex,
        const string& keyValue)
    {
        if (keyFieldIndex < 0)
            return false;

        vector<string> records;

        if (!readAllRecords(filePath, records))
            return false;

        vector<string> remaining;
        bool found = false;

        for (size_t i = 0; i < records.size(); i++)
        {
            vector<string> fields = parseRecord(records[i]);

            if (keyFieldIndex < static_cast<int>(fields.size()) &&
                fields[keyFieldIndex] == keyValue)
            {
                found = true;
            }
            else
            {
                remaining.push_back(records[i]);
            }
        }

        if (!found)
        {
            cout << "[File] Record not found." << endl;
            return false;
        }

        return writeTempAndReplace(filePath, remaining);
    }

    // Search for records using an exact field match.
    bool searchRecords(
        const string& filePath,
        int fieldIndex,
        const string& keyword,
        vector<string>& results)
    {
        results.clear();

        if (fieldIndex < 0)
            return false;

        vector<string> records;

        if (!readAllRecords(filePath, records))
            return false;

        for (size_t i = 0; i < records.size(); i++)
        {
            vector<string> fields = parseRecord(records[i]);

            if (fieldIndex < static_cast<int>(fields.size()) &&
                fields[fieldIndex] == keyword)
            {
                results.push_back(records[i]);
            }
        }

        return true;
    }

    // Count the records in a file.
    int countRecords(const string& filePath)
    {
        vector<string> records;

        if (!readAllRecords(filePath, records))
            return -1;

        return static_cast<int>(records.size());
    }

}
