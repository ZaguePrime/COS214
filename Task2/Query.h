#ifndef QUERY_H
#define QUERY_H

#include "Record.h"
#include <string>


class Query
{
private:
    Record* queryObject = nullptr;
    std::string table = "ERROR";
    std::string operation = "ERROR";
public:
    Query();
    
    std::string getOperation(){return this->operation;};
    std::string getTable() {return this->table;};
    Record* getRecord(){return this->queryObject;};

    void setOperation(std::string op){this->operation = op;};
    void setTable(std::string t){this->table = t;};
    void setRecord(Record* record){this->queryObject = record;};


    ~Query();
};

#endif