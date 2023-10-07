#include "Table.h"

// public functions

// Constructor
Table::Table()
{
}

std::string Table::queryHandler(std::string query)
{
    return "Not implemented";
}

std::string Table::to_string()
{
    return "Not implemented";
}

// Destructor
Table::~Table()
{
}

// private functions
bool Table::insertRecord(Record *value)
{
    records.push_back(value);
}

bool Table::deleteRecord(Record *value)
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

bool Table::checkIfRecordMatch(Record *value, Record *currentElem)
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

std::string Table::selectRecord(Record *value)
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

bool Table::updateRecord(Record *value)
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

bool Table::applyUpdate(Record *value, Record *currElem)
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

bool Table::syntaxCheck(std::string query)
{

}

