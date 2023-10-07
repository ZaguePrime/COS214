#include "SyntaxChecker.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{
}

Query *SyntaxChecker::getQuery(std::string query)
{
    error = false;
    this->query = nullptr;
    this->query = new Query();
    this->query->setRecord(new Record());

    syntaxCheck(query);

    if (error)
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
    else
    {
        return;
    }
    std::cout << "made it here" << std::endl;
}

void SyntaxChecker::checkSelect(std::string &query)
{
    for (int i = 0; i < SelectCheckOrder.size() && !error; i++)
    {
        std::string word = getWord(query);
        switch (SelectCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(word);
            break;

        case Check::FIELDS:
            checkFields(word);
            break;
        case Check::FROM:
            checkFrom(word);
            break;
        case Check::TABLE:
            checkTable(word);

            break;
        case Check::WHERE:
            checkWhere(word);

            break;
        case Check::INTO:
            checkInto(word);

            break;
        case Check::SET:
            checkSet(word);

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(word);

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
        std::string word = getWord(query);

        switch (InsertCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(word);
            break;

        case Check::FIELDS:
            checkFields(word);
            break;
        case Check::FROM:
            checkFrom(word);
            break;
        case Check::TABLE:
            checkTable(word);

            break;
        case Check::WHERE:
            checkWhere(word);

            break;
        case Check::INTO:
            checkInto(word);

            break;
        case Check::SET:
            checkSet(word);

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(word);

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
        std::string word = getWord(query);

        switch (UpdateCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(word);
            break;

        case Check::FIELDS:
            checkFields(word);
            break;
        case Check::FROM:
            checkFrom(word);
            break;
        case Check::TABLE:
            checkTable(word);

            break;
        case Check::WHERE:
            checkWhere(word);

            break;
        case Check::INTO:
            checkInto(word);

            break;
        case Check::SET:
            checkSet(word);

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(word);

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
        std::string word = getWord(query);
        switch (DeleteCheckOrder[i])
        {
        case Check::OPERATION:
            checkOperation(word);
            break;

        case Check::FIELDS:
            checkFields(word);
            break;
        case Check::FROM:
            checkFrom(word);
            break;
        case Check::TABLE:
            checkTable(word);

            break;
        case Check::WHERE:
            checkWhere(word);

            break;
        case Check::INTO:
            checkInto(word);

            break;
        case Check::SET:
            checkSet(word);

            break;
        case Check::FIELD_VALUE:
            checkFieldValue(word);

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
    if (Word == "key")
    {
        this->query->getRecord()->setName(Word);
        return error;
    }
    else if (Word == "name")
    {
        this->query->getRecord()->setName(Word);
        return error;
    }
    else if (Word == "surname")
    {
        this->query->getRecord()->setName(Word);
        return error;
    }
    else if (Word == "value")
    {
        this->query->getRecord()->setName(Word);
        return error;
    }
    else if (Word == "*")
    {
        this->query->getRecord()->setName(Word);
        return error;
    }
    error = true;
    return error;
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
    std::string field = extractField(Word);
    std::string value = extractValue(Word);
    if (field == "" || value == "")
    {
        error = true;
        return error;
    }
    else if (field == "key")
    {
        this->query->getRecord()->setKey(stoi(value));
        this->query->getRecord()->setName(value);
        this->query->getRecord()->setSurname(value);
        this->query->getRecord()->setValue(stod(value));
        return error;
    } /*
     else if (field == "name")
     {
         this->query->getRecord()->setName(value);
     }
     else if (field == "surname")
     {
         this->query->getRecord()->setSurname(value);
     }
     else if (field == "value")
     {
     }*/
    else
    {
        error = true;
        return error;
    }
}

std::string SyntaxChecker::extractValue(const std::string &input)
{
    // Find the position of the '=' character
    size_t equalSignPos = input.find('=');

    // If the '=' character is found, extract the substring after it
    if (equalSignPos != std::string::npos)
    {
        return input.substr(equalSignPos + 1);
    }

    // If '=' is not found, return an empty string
    return "";
}

std::string SyntaxChecker::extractField(const std::string &input)
{
    // Find the position of the '=' character
    size_t equalSignPos = input.find('=');

    // If the '=' character is found, extract the substring before it
    if (equalSignPos != std::string::npos)
    {
        return input.substr(0, equalSignPos);
    }

    // If '=' is not found, return an empty string
    return "";
}

bool SyntaxChecker::checkValues(std::string Word)
{
    if (extractWord(Word) != "values")
    {
        error = true;
        return error;
    }

    std::string params = extractContentInsideParentheses(Word);
    if (params == "")
    {
        true;
        return error;
    }

    vector<std::string> splitParams = splitString(params, ',');
    if (splitParams.size() != 4)
    {
        true;
        return error;
    }

    this->query->getRecord()->setName(splitParams[1]);
    this->query->getRecord()->setSurname(splitParams[2]);
    this->query->getRecord()->setValue(stod(splitParams[3]));
    return error;
}

std::string SyntaxChecker::extractWord(const std::string &input)
{
    // Find the position of the opening parenthesis
    size_t pos = input.find('(');

    // If the opening parenthesis is found, extract the word before it
    if (pos != std::string::npos)
    {
        return input.substr(0, pos);
    }

    // If no opening parenthesis is found, return the entire input string
    return input;
}

std::string SyntaxChecker::extractContentInsideParentheses(const std::string &input)
{
    // Find the positions of the opening and closing parentheses
    size_t openParenthesisPos = input.find('(');
    size_t closeParenthesisPos = input.find(')');

    // If both parentheses are found and the closing parenthesis comes after the opening one
    if (openParenthesisPos != std::string::npos && closeParenthesisPos != std::string::npos && closeParenthesisPos > openParenthesisPos)
    {
        // Extract the content between the parentheses
        return input.substr(openParenthesisPos + 1, closeParenthesisPos - openParenthesisPos - 1);
    }

    // If parentheses are not found or in an incorrect order, return an empty string
    return "";
}

std::vector<std::string> SyntaxChecker::splitString(const std::string &input, char delimiter)
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