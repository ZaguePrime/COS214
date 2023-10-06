#include "Database.h"

// public functions

// Constructor
Database::Database()
{
}

std::string Database::queryHandler(std::string query)
{
    return "Not implemented";
}

std::string Database::to_string()
{
    return "Not implemented";
}

// Destructor
Database::~Database()
{
}

// private functions
bool Database::insertRecord(Record *value)
{
    records.push_back(value);
}

bool Database::deleteRecord(Record *value)
{
    bool deleted = false;

    for (int i = 0; i < records.size(); i++)
    {
        if (checkIfRecordMatch(value, records[i]))
        {
            records.erase(records.begin() + i);
            deleted = true;
        }
    }

    return deleted;
}

bool Database::checkIfRecordMatch(Record *value, Record *currentElem)
{
    if (value->getKey() != -1)
    {
        if (value->getKey() != currentElem->getKey())
        {
            return false;
        }
    }

    if (value->getName() != "")
    {
        if (value->getName() != currentElem->getName())
        {
            return false;
        }
    }

    if (value->getSurname() != "")
    {
        if (value->getSurname() != currentElem->getSurname())
        {
            return false;
        }
    }

    if (value->getValue() >= 0)
    {
        if (value->getValue() - currentElem->getValue() > 0.00000001)
        {
            return false;
        }
    }

    return true;
}

std::string Database::selectRecord(Record *value)
{

    std::string result;

    for (int i = 0; i < records.size(); i++)
    {
        if (checkIfRecordMatch(value, records[i]))
        {
            result += records[i]->to_string() + "\n";
        }
    }

    return result;
}

bool Database::updateRecord(Record *value)
{
    bool updated = false;

    for (int i = 0; i < records.size(); i++)
    {
        if (checkIfRecordMatch(value, records[i]))
        {
            records.erase(records.begin() + i);
            updated = true;
        }
    }

    return updated;
    return false;
}

void Database::applyUpdate(Record *value, Record *currElem)
{
    
}

bool Database::syntaxCheck(std::string query)
{
    return false;
}
