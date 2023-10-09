#ifndef NEW_DB_H
#define new_DB_H

#include "db.h"
#include <vector>
#include <iostream>

class NewDatabase : public db
{
private:
    Database *data;

public:
    NewDatabase(Database *data);
    std::string combineStrings(const std::vector<std::string> &strings);
    std::string databaseQuery(std::string query);
    std::vector<std::string> splitString(const std::string &input, char delimiter);
    virtual~NewDatabase();
};

#endif