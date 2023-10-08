#include "NewDatabase.h"

NewDatabase::NewDatabase(Database *data)
{
    ch->SelectCheckOrder.push_back(Check::FROM);
    ch->SelectCheckOrder.push_back(Check::TABLE);
    ch->SelectCheckOrder.push_back(Check::OPERATION);
    ch->SelectCheckOrder.push_back(Check::FIELDS);

    ch->UpdateCheckOrder.push_back(Check::OPERATION);
    ch->UpdateCheckOrder.push_back(Check::TABLE);
    ch->UpdateCheckOrder.push_back(Check::SET);
    ch->UpdateCheckOrder.push_back(Check::FIELD_VALUE);
    ch->UpdateCheckOrder.push_back(Check::WHERE);
    ch->UpdateCheckOrder.push_back(Check::FIELD_VALUE);

    ch->DeleteCheckOrder.push_back(Check::FROM);
    ch->DeleteCheckOrder.push_back(Check::TABLE);
    ch->DeleteCheckOrder.push_back(Check::OPERATION);
    ch->DeleteCheckOrder.push_back(Check::WHERE);
    ch->DeleteCheckOrder.push_back(Check::FIELD_VALUE);

    ch->InsertCheckOrder.push_back(Check::INTO);
    ch->InsertCheckOrder.push_back(Check::TABLE);
    ch->InsertCheckOrder.push_back(Check::OPERATION);
    ch->InsertCheckOrder.push_back(Check::INSERT_VALUES);

    this->data = data;
}
std::string NewDatabase::databaseQuery(std::string query)
{
    // Query *q = ch->getQuery(query);
    if (true)
    {
        std::vector<std::string> split = splitString(query, ' ');
        if (split.size() >= 4 && split[2] == "select")
        {
        std::string temp1 = split[0];
        std::string temp2 = split[1];

        split[0] = split[2];
        split[1] = split[3];
        split[2] = temp1;
        split[3] = temp2;
        }
        else if(split.size() >= 3 && (split[2] == "delete" || split[2] == "insert")){
            std::string temp = split[2];
            split[2] = split[1];
            split[1] = split[0];
            split[0] = temp;
        }else{
            return "query error: cannot pass to legacy format";
        }
        std::string newQuery = combineStrings(split);
        std::cout << "after swap: " << newQuery << std::endl;
        return data->databaseQuery(newQuery);
    }
    return "fail in NewDatabase";
}

std::string NewDatabase::combineStrings(const std::vector<std::string> &strings)
{
    std::ostringstream combinedString;

    for (const auto &str : strings)
    {
        combinedString << str << ' ';
    }

    return combinedString.str();
}

std::vector<std::string> NewDatabase::splitString(const std::string &input, char delimiter)
{
    std::istringstream ss(input);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}
NewDatabase::~NewDatabase()
{
}