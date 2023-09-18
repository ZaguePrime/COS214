#include "Exception.h"
Exception::Exception(std::string error, std::string message)//
{
    this->message = message;
    this->error = error;
}

std::string Exception::toString()
{
    std::stringstream result;

    result << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    result << "Error: " << this->error << std::endl;
    result << "Message: " << this->message << std::endl;
    result << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;

    return result.str();
}

Exception::~Exception()
{
}