#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Message
{
private:
    std::string error;
    std::string message;

public:

    Message(std::string error, std::string message) : error(error), message(message) {}
    ~Message() {}

    std::string getError() const { return error; }
    std::string getMessage() const { return message; }
};


#endif