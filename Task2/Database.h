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
    Query* formatQuery(std::string stringQuery);
public:
    Database(/* args */);
    void addTable(Table* table);
    void removeTable(std::string name);

    std::string databaseQuery(std::string query);

    ~Database();
};


#endif