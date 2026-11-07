
#include <iostream>
#include <string>
#include <vector>

#include "filehandling/file_manager.h"

using namespace std;
using namespace fm;

int passed = 0;
int failed = 0;

void check(bool condition, const string& testName)
{
    if (condition)
    {
        cout << "PASS: " << testName << endl;
        passed++;
    }
    else
    {
        cout << "FAIL: " << testName << endl;
        failed++;
    }
}

int main()
{
    const string TEST_FILE = "data/test_records.txt";

    cout << "\n===== SMARTBITE FILE MANAGER TEST =====\n\n";

    // 1. Create file
    check(ensureFileExists(TEST_FILE), "Create file");
    check(fileExists(TEST_FILE), "Check file existence");

    // 2. Clear previous test records
    vector<string> empty;
    check(writeAllRecords(TEST_FILE, empty), "Clear test file");

    // 3. Append records
    check(appendRecord(TEST_FILE,
          {"1", "Rahul Sharma", "rahul", "hash123"}),
          "Append Rahul");

    check(appendRecord(TEST_FILE,
          {"2", "Priya Verma", "priya", "hash456"}),
          "Append Priya");

    check(appendRecord(TEST_FILE,
          {"3", "Amit Kumar", "amit", "hash789"}),
          "Append Amit");

    // 4. Count records
    check(countRecords(TEST_FILE) == 3, "Count three records");

    // 5. Read records
    vector<string> records;

    check(readAllRecords(TEST_FILE, records), "Read records");
    check(records.size() == 3, "Verify record count");

    // 6. Parse record and preserve spaces
    vector<string> fields = parseRecord(records[0]);

    check(fields.size() == 4 &&
          fields[1] == "Rahul Sharma",
          "Preserve spaces in names");

    // 7. Search record
    vector<string> results;

    check(searchRecords(TEST_FILE, 2, "priya", results) &&
          results.size() == 1,
          "Search for Priya");

    check(searchRecords(TEST_FILE, 2, "unknown", results) &&
          results.empty(),
          "Search for missing user");

    // 8. Update record
    check(updateRecord(TEST_FILE, 2, "rahul",
          {"1", "Rahul Sharma", "rahul", "newhash123"}),
          "Update Rahul record");

    check(searchRecords(TEST_FILE, 2, "rahul", results) &&
          results.size() == 1 &&
          parseRecord(results[0])[3] == "newhash123",
          "Verify updated record");

    // 9. Delete record
    check(deleteRecord(TEST_FILE, 2, "amit"),
          "Delete Amit");

    check(countRecords(TEST_FILE) == 2,
          "Verify count after deletion");

    // 10. Invalid field index
    check(!searchRecords(TEST_FILE, -1, "rahul", results),
          "Reject negative search index");

    // 11. Missing file
    check(!readAllRecords("data/missing_test.txt", records),
          "Handle missing file");

    // 12. Empty file
    check(ensureFileExists("data/empty_test.txt"),
          "Create empty file");

    check(readAllRecords("data/empty_test.txt", records) &&
          records.empty(),
          "Read empty file");

    cout << "\n====================================\n";
    cout << "PASSED: " << passed << endl;
    cout << "FAILED: " << failed << endl;
    cout << "====================================\n";

    return failed == 0 ? 0 : 1;
}
