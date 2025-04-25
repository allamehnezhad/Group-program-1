#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

enum class DataType { STRING, INT, FLOAT };

class Column {
public:
    string name;
    DataType type;
    Column(string n, DataType t) : name(n), type(t) {}
};

class Schema {
public:
    string tableName;
    vector<Column> columns;
    Schema(string name) : tableName(name) {}
    void addColumn(string name, DataType type) {
        columns.emplace_back(name, type);
    }
    bool hasColumn(const string& colName) {
        for (auto& col : columns) {
            if (col.name == colName) return true;
        }
        return false;
    }
    int getColumnIndex(const string& colName) {
        for (int i = 0; i < columns.size(); i++) {
            if (columns[i].name == colName) return i;
        }
        return -1;
    }
};

struct MetaData {
    vector<string> values;
};

struct Record {
    string tableName;
    MetaData data;
    bool isDeleted = false;
};

vector<string> splitInput(const string& input) {
    vector<string> result;
    stringstream ss(input);
    string item;
    while (getline(ss, item, ',')) {
        item.erase(remove_if(item.begin(), item.end(), ::isspace), item.end());
        result.push_back(item);
    }
    return result;
}

int main() {
    Schema student("students");
    student.addColumn("id", DataType::STRING);
    student.addColumn("name", DataType::STRING);
    student.addColumn("major", DataType::STRING);

    vector<Record> records;
}