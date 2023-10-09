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
        std::cout << "found error" << endl;
        delete this->query;
        return nullptr;
    }
    Query* temp = this->query;
    this->query = nullptr;
    return temp;
}

SyntaxChecker::~SyntaxChecker()
{
    // if(query != nullptr)
    delete query;
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
}

void SyntaxChecker::checkSelect(std::string &query)
{
    std::cout << "=====log=====" << endl;

    for (int i = 0; i < SelectCheckOrder.size() && !error; i++)
    {
        std::string word = getWord(query);
        std::cout << "word: |" << word << endl;
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
        case Check::INSERT_VALUES:
            checkValues(word);
            break;
        default:
            error = true;
            return;
        }
        std::cout << "error: " << this->error << endl;
        deleteWord(query);
    }
    std::cout << "=====log=====" << endl;
}
void SyntaxChecker::checkInsert(std::string &query)
{
    std::cout << "=====log=====" << endl;

    for (int i = 0; i < InsertCheckOrder.size() && !error; i++)
    {
        std::string word = getWord(query);
        std::cout << "word: |" << word << endl;

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
        case Check::INSERT_VALUES:
            checkValues(word);
            break;
        default:
            error = true;
            return;
        }
        std::cout << "error: " << this->error << endl;

        deleteWord(query);
    }
    std::cout << "=====log=====" << endl;
}
void SyntaxChecker::checkUpdate(std::string &query)
{
    std::cout << "=====log=====" << endl;
    for (int i = 0; i < UpdateCheckOrder.size() && !error; i++)
    {
        std::string word = getWord(query);
        std::cout << "word: |" << word << endl;

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
        case Check::INSERT_VALUES:
            checkValues(word);
            break;
        default:
            error = true;
            return;
        }
        std::cout << "error: " << this->error << endl;

        deleteWord(query);
    }
    std::cout << "=====log=====" << endl;
}
void SyntaxChecker::checkDelete(std::string &query)
{
    std::cout << "=====log=====" << endl;
    for (int i = 0; i < DeleteCheckOrder.size() && !error; i++)
    {
        std::string word = getWord(query);
        std::cout << "word: |" << word << endl;

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
        case Check::INSERT_VALUES:
            checkValues(word);
            break;
        default:
            error = true;
            return;
        }
        std::cout << "error: " << this->error << endl;

        deleteWord(query);
    }
    std::cout << "=====log=====" << endl;
}

std::string SyntaxChecker::getWord(std::string &query)
{
    std::string firstWord = "";
    size_t firstNonSpace = query.find_first_not_of(' ');

    if (firstNonSpace != std::string::npos)
    {
        size_t firstSpace = query.find_first_of(' ', firstNonSpace);
        firstWord = query.substr(firstNonSpace, firstSpace - firstNonSpace);
    }
    return firstWord;
}

std::string SyntaxChecker::deleteWord(std::string &query)
{
    size_t firstNonSpace = query.find_first_not_of(' ');

    if (firstNonSpace != std::string::npos)
    {
        size_t firstSpace = query.find_first_of(' ', firstNonSpace);
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
    this->query->setTable(Word);
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
    bool flag = false;

    // cout << field << "|========|" << value << endl;
    if (field == "" || value == "")
    {
        error = true;
    }
    else if (field == "key")
    {
        this->query->getRecord()->setKey(stoi(value));
    }
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
        flag = true;
        this->query->getRecord()->setValue(stod(value));
    }
    else
    {
        error = true;
    }

    if (!flag)
    {
        this->query->getRecord()->setValue(-1);
    }
    return error;
}

std::string SyntaxChecker::extractValue(const std::string &input)
{
    size_t equalSignPos = input.find('=');
    if (equalSignPos != std::string::npos)
    {
        return input.substr(equalSignPos + 1);
    }

    return "";
}

std::string SyntaxChecker::extractField(const std::string &input)
{
    size_t equalSignPos = input.find('=');

    if (equalSignPos != std::string::npos)
    {
        return input.substr(0, equalSignPos);
    }
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
    size_t pos = input.find('(');

    if (pos != std::string::npos)
    {
        return input.substr(0, pos);
    }
    return input;
}

std::string SyntaxChecker::extractContentInsideParentheses(const std::string &input)
{
    size_t openParenthesisPos = input.find('(');
    size_t closeParenthesisPos = input.find(')');

    if (openParenthesisPos != std::string::npos && closeParenthesisPos != std::string::npos && closeParenthesisPos > openParenthesisPos)
    {
        return input.substr(openParenthesisPos + 1, closeParenthesisPos - openParenthesisPos - 1);
    }

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