#ifndef SYNTAX_CHECKER_H
#define SYNTAX_CHECKER_H

#include "Query.h"
#include "Record.h"
#include <string>
#include <vector>


enum Check;

class SyntaxChecker
{
private:
    bool error = false;
    Query* query = nullptr;



    std::vector<std::string> fields;
    std::vector<std::string> tables;

    std::string getWord(std::string &query);
    std::string deleteWord(std::string &query);

    bool checkOperation(std::string Word);
    bool checkFields(std::string Word);
    bool checkFrom(std::string Word);
    bool checkTable(std::string Word);
    bool checkWhere(std::string Word);
    bool checkInto(std::string Word);
    bool checkSet(std::string Word);
    bool checkFieldValue(std::string Word);

    void syntaxCheck(std::string query);

    void checkSelect(std::string &query);
    void checkInsert(std::string &query);
    void checkUpdate(std::string &query);
    void checkDelete(std::string &query);

public:

    std::vector<Check> SelectCheckOrder;
    std::vector<Check> UpdateCheckOrder;
    std::vector<Check> DeleteCheckOrder;
    std::vector<Check> InsertCheckOrder;

    enum Check
    {
        OPERATION,
        FIELDS,
        FROM,
        TABLE,
        WHERE,
        INTO,
        SET,
        FIELD_VALUE
    };

    SyntaxChecker();
    ~SyntaxChecker();

    Query *getQuery(std::string query);
    
};

#endif