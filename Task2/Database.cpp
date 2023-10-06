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
        if(applyUpdate(value, records[i]))
        {
            updated = true;
        }
    }

    return updated;
}

bool Database::applyUpdate(Record *value, Record *currElem)
{

    if (value->getKey() != -1)
    {
        if (value->getKey() != currElem->getKey())
        {
            applyChanges(value, currElem);
            return true;
        }
    }

    if (value->getName() != "")
    {
        if (value->getName() != currElem->getName())
        {
            applyChanges(value, currElem);
            return true;
        }
    }

    if (value->getSurname() != "")
    {
        if (value->getSurname() != currElem->getSurname())
        {
            applyChanges(value, currElem);
            return true;
        }
    }

    if (value->getValue() >= 0)
    {
        if (value->getValue() - currElem->getValue() > 0.00000001)
        {
            applyChanges(value, currElem);
            return true;
        }
    }
    return false;
}

void applyChanges(Record *value, Record *currElem)
{
    if (value->getName() != "")
    {
        if (value->getName() != currElem->getName())
        {
            currElem->setName(value->getName());
            return;
        }
    }

    if (value->getSurname() != "")
    {
        if (value->getSurname() != currElem->getSurname())
        {
            currElem->setSurname(value->getSurname());
            return;
        }
    }

    if (value->getValue() >= 0)
    {
        if (value->getValue() - currElem->getValue() > 0.00000001)
        {
            currElem->setValue(value->getValue());
            return;
        }
    }
}

bool Database::syntaxCheck(std::string query)
{
    




    return true;
}

std::string Database::getWord(std::string query)
{
    std::string firstWord = "";

    // Find the position of the first non-space character
    size_t firstNonSpace = query.find_first_not_of(' ');

    // If there are no non-space characters, the string is empty or contains only spaces
    if (firstNonSpace != std::string::npos) {
        // Find the position of the first space after the first non-space character
        size_t firstSpace = query.find_first_of(' ', firstNonSpace);
        // Extract the first word using substr
        firstWord = query.substr(firstNonSpace, firstSpace - firstNonSpace);

    }
    
    return firstWord;
}


std::string Database::deleteWord(std::string &query) {
    // Find the position of the first non-space character
    size_t firstNonSpace = query.find_first_not_of(' ');

    // If there are no non-space characters, the string is empty or contains only spaces
    if (firstNonSpace != std::string::npos) {
        // Find the position of the first space after the first non-space character
        size_t firstSpace = query.find_first_of(' ', firstNonSpace);

        // Erase the first word and any spaces until the second word
        query.erase(firstNonSpace, firstSpace - firstNonSpace);
    }

    return query;
}

