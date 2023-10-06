#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "Record.h"
#include "Message.h"

class Database
{
private:
    std::vector<Record*> records;
    
    bool insertRecord(Record* value);
    bool deleteRecord(Record* value);
    std::vector<Record*> selectRecord(Record* value);
    bool updateRecord(Record* value);

    bool syntaxCheck(std::string query);

public:
    Database();

    std::string queryHandler(std::string query);


    std::string to_string();

    ~Database();
};


#endif