#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <algorithm>
#include "Record.h"
#include "Message.h"

class Table
{
private:
    std::vector<Record*> records;
    std::string name;
    
    bool insertRecord(Record* value);
    bool deleteRecord(Record* value);
    std::string selectRecord(Record* value);
    bool updateRecord(Record* value);
    bool applyUpdate(Record* value, Record* currElem);
    void applyChanges(Record* value, Record* currElem);
    bool checkIfRecordMatch(Record* value, Record* currentElem);
    bool syntaxCheck(std::string query);


public:
    Table(std::string name);

    std::string queryHandler(std::string operation,  Record* record);
    std::string getName(){return this->name;};

    std::string to_string();

    ~Table();
};


#endif