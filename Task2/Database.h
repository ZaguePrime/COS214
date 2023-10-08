#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"
#include "Query.h"
#include "SyntaxChecker.h"
#include <vector>
#include <string>


class Database
{
private:
    std::vector<Table*> tables;
    SyntaxChecker* checker = new SyntaxChecker();
    
    int getTableIndex(std::string t);

public:
    Database(/* args */);
    void addTable(Table* table){tables.push_back(table);};

    std::string databaseQuery(std::string query);

    ~Database();
};


#endif