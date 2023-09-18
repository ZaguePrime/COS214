#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>//
#include <sstream>

class Exception
{
private:
    std::string message;
    std::string error;
public:
    Exception(std::string error, std::string message);
    std::string toString();
    ~Exception();
};



#endif