#include "Database.h"

std::string Database::databaseQuery(std::string query)
{
    Query *q = checker->getQuery(query);
    if (q != nullptr)
    {
        int tIndex = getTableIndex(q->getTable());
        if (tIndex !=-1)
        {
            return tables[tIndex]->queryHandler(q->getOperation(),q->getRecord());
        }
    }
    return "fail in database";
}

Database::Database()
{
    checker->SelectCheckOrder.push_back(Check::OPERATION);
    checker->SelectCheckOrder.push_back(Check::FIELDS);
    checker->SelectCheckOrder.push_back(Check::FROM);
    checker->SelectCheckOrder.push_back(Check::TABLE);

    checker->UpdateCheckOrder.push_back(Check::OPERATION);
    checker->UpdateCheckOrder.push_back(Check::TABLE);
    checker->UpdateCheckOrder.push_back(Check::SET);
    checker->UpdateCheckOrder.push_back(Check::FIELD_VALUE);
    checker->UpdateCheckOrder.push_back(Check::WHERE);
    checker->UpdateCheckOrder.push_back(Check::FIELD_VALUE);

    checker->DeleteCheckOrder.push_back(Check::OPERATION);
    checker->DeleteCheckOrder.push_back(Check::FROM);
    checker->DeleteCheckOrder.push_back(Check::TABLE);
    checker->DeleteCheckOrder.push_back(Check::WHERE);
    checker->DeleteCheckOrder.push_back(Check::FIELD_VALUE);

    checker->InsertCheckOrder.push_back(Check::OPERATION);
    checker->InsertCheckOrder.push_back(Check::INTO);
    checker->InsertCheckOrder.push_back(Check::TABLE);
    checker->InsertCheckOrder.push_back(Check::INSERT_VALUES);

    tables.push_back(new Table("people"));
    tables[0]->insertRecord(new Record(0,"harry","bob",10.2));
}

int Database::getTableIndex(std::string t)
{
    for (int i = 0; i < tables.size(); i++)
    {
        if(tables[i]->getName() == t)
        {
            return i;
        }
    }
    return -1;
    
}

Database::~Database()
{
}
