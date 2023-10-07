#include "SyntaxChecker.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{
}

Query *SyntaxChecker::getQuery(std::string query)
{
    error =false;
    this->query = nullptr;
    this->query = new Query();
    this->query->setRecord(new Record());

    syntaxCheck(query);

    if(error)
    {
        delete this->query;
        return nullptr;
    }

    return this->query;
}

SyntaxChecker::~SyntaxChecker()
{
}

void SyntaxChecker::syntaxCheck(std::string query)
{
    std::string word = getWord(query);

    if (word == "")
    {
        error = true;
        return;
    }

    checkOperation(word);
    if (error)
    {
        return;
    }

    std::vector<Check> *opertaionType;

    if (this->query->getOperation() == "select")
    {
        this->checkSelect(query);
    }
    else if (this->query->getOperation() == "update")
    {
        this->checkUpdate(query);
    }
    else if (this->query->getOperation() == "delete")
    {
        this->checkDelete(query);
    }
    else if (this->query->getOperation() == "insert")
    {
        this->checkInsert(query);
    }
}

void SyntaxChecker::checkSelect(std::string &query)
{
    for (int i = 0; i < SelectCheckOrder.size() && !error; i++)
    {
        switch (SelectCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(getWord(query));
            break;

        case Check::FIELDS:
            checkFields(getWord(query));
            break;
        case Check::FROM:
            checkFrom(getWord(query));
            break;
        case Check::TABLE:
            checkTable(getWord(query));

            break;
        case Check::WHERE:
            checkWhere(getWord(query));

            break;
        case Check::INTO:
            checkInto(getWord(query));

            break;
        case Check::SET:
            checkSet(getWord(query));

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(getWord(query));

            break;
        default:
            error = true;
            return;
        }
    }
}
void SyntaxChecker::checkInsert(std::string &query)
{
        for (int i = 0; i < InsertCheckOrder.size() && !error; i++)
    {
        switch (SelectCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(getWord(query));
            break;

        case Check::FIELDS:
            checkFields(getWord(query));
            break;
        case Check::FROM:
            checkFrom(getWord(query));
            break;
        case Check::TABLE:
            checkTable(getWord(query));

            break;
        case Check::WHERE:
            checkWhere(getWord(query));

            break;
        case Check::INTO:
            checkInto(getWord(query));

            break;
        case Check::SET:
            checkSet(getWord(query));

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(getWord(query));

            break;
        default:
            error = true;
            return;
        }
    }
}
void SyntaxChecker::checkUpdate(std::string &query)
{
        for (int i = 0; i < UpdateCheckOrder.size() && !error; i++)
    {
        switch (SelectCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(getWord(query));
            break;

        case Check::FIELDS:
            checkFields(getWord(query));
            break;
        case Check::FROM:
            checkFrom(getWord(query));
            break;
        case Check::TABLE:
            checkTable(getWord(query));

            break;
        case Check::WHERE:
            checkWhere(getWord(query));

            break;
        case Check::INTO:
            checkInto(getWord(query));

            break;
        case Check::SET:
            checkSet(getWord(query));

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(getWord(query));

            break;
        default:
            error = true;
            return;
        }
    }
}
void SyntaxChecker::checkDelete(std::string &query)
{
        for (int i = 0; i < DeleteCheckOrder.size() && !error; i++)
    {
        switch (SelectCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(getWord(query));
            break;

        case Check::FIELDS:
            checkFields(getWord(query));
            break;
        case Check::FROM:
            checkFrom(getWord(query));
            break;
        case Check::TABLE:
            checkTable(getWord(query));

            break;
        case Check::WHERE:
            checkWhere(getWord(query));

            break;
        case Check::INTO:
            checkInto(getWord(query));

            break;
        case Check::SET:
            checkSet(getWord(query));

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(getWord(query));

            break;
        default:
            error = true;
            return;
        }
    }
}

std::string SyntaxChecker::getWord(std::string &query)
{
    std::string firstWord = "";

    // Find the position of the first non-space character
    size_t firstNonSpace = query.find_first_not_of(' ');

    // If there are no non-space characters, the string is empty or contains only spaces
    if (firstNonSpace != std::string::npos)
    {
        // Find the position of the first space after the first non-space character
        size_t firstSpace = query.find_first_of(' ', firstNonSpace);
        // Extract the first word using substr
        firstWord = query.substr(firstNonSpace, firstSpace - firstNonSpace);
    }
    return firstWord;
}

std::string SyntaxChecker::deleteWord(std::string &query)
{
    // Find the position of the first non-space character
    size_t firstNonSpace = query.find_first_not_of(' ');

    // If there are no non-space characters, the string is empty or contains only spaces
    if (firstNonSpace != std::string::npos)
    {
        // Find the position of the first space after the first non-space character
        size_t firstSpace = query.find_first_of(' ', firstNonSpace);

        // Erase the first word and any spaces until the second word
        query.erase(firstNonSpace, firstSpace - firstNonSpace);
    }

    return query;
}

bool SyntaxChecker::checkOperation(std::string Word)
{
    if (Word == "select" || Word == "SELECT")
    {
        this->query->setOperation("select");
    }
    else if (Word == "update" || Word == "UPDATE")
    {
        this->query->setOperation("update");
    }
    else if (Word == "delete" || Word == "DELETE")
    {
        this->query->setOperation("delete");
    }
    else if (Word == "insert" || Word == "INSERT")
    {
        this->query->setOperation("insert");
    }
    else
    {
        error = true;
    }
    return error;
}

bool SyntaxChecker::checkFields(std::string Word)
{
}

bool SyntaxChecker::checkFrom(std::string Word)
{
    if (Word != "from" && Word != "FROM")
    {
        error = true;
    }

    return error;
}

bool SyntaxChecker::checkTable(std::string Word)
{
    return error;
}

bool SyntaxChecker::checkWhere(std::string Word)
{
    if (Word != "where" && Word != "WHERE")
    {
        error = true;
    }
    return error;
}

bool SyntaxChecker::checkInto(std::string Word)
{

    if (Word != "into" && Word != "INTO")
    {
        error = true;
    }
    return error;
}

bool SyntaxChecker::checkSet(std::string Word)
{

    if (Word != "set" && Word != "SET")
    {
        error = true;
    }
    return error;
}

bool SyntaxChecker::checkFieldValue(std::string Word)
{
}