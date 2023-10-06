#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <algorithm>
#include "Record.h"
#include "Message.h"

class Database
{
private:
    std::vector<Record*> records;
    
    bool insertRecord(Record* value);
    bool deleteRecord(Record* value);
    std::string selectRecord(Record* value);
    bool updateRecord(Record* value);
    bool applyUpdate(Record* value, Record* currElem);
    void applyChanges(Record* value, Record* currElem);
    bool checkIfRecordMatch(Record* value, Record* currentElem);
    bool syntaxCheck(std::string query);

public:
    Database();

    std::string queryHandler(std::string query);


    std::string to_string();

    ~Database();
};


#endif