#ifndef DB_H
#define DB_H

#include <string>
#include "SyntaxChecker.h"
#include "Database.h"

class db
{
protected:
    SyntaxChecker* ch = new SyntaxChecker();
public:
    db();
    virtual std::string databaseQuery(std::string query) =0;
    virtual ~db();
};


#endif