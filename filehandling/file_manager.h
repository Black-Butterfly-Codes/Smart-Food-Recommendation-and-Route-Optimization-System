#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

namespace fm
{
    // Record format helpers
    std::string encodeRecord(const std::vector<std::string>& fields);
    std::vector<std::string> parseRecord(const std::string& line);

    // File existence
    bool fileExists(const std::string& filePath);
    bool ensureFileExists(const std::string& filePath);

    // Whole-file operations
    bool writeAllRecords(const std::string& filePath,
                         const std::vector<std::string>& records);

    bool readAllRecords(const std::string& filePath,
                        std::vector<std::string>& records);

    // Individual record operations
    bool appendRecord(const std::string& filePath,
                      const std::vector<std::string>& fields);

    bool updateRecord(const std::string& filePath,
                      int keyFieldIndex,
                      const std::string& keyValue,
                      const std::vector<std::string>& newFields);

    bool deleteRecord(const std::string& filePath,
                      int keyFieldIndex,
                      const std::string& keyValue);

    bool searchRecords(const std::string& filePath,
                       int fieldIndex,
                       const std::string& keyword,
                       std::vector<std::string>& results);

    int countRecords(const std::string& filePath);
}

#endif
