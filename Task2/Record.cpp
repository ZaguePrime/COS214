// Record.cpp
#include "Record.h"

int Record::keyCounter = 0;

Record::Record() : key(keyCounter++)
{
    // Other attribute initialization if needed
    name = "";
    surname = "";
    value = 0.0;
}

int Record::getKey() const
{
    return key;
}

void Record::setKey(int newKey)
{
    key = newKey;
}

const std::string &Record::getName() const
{
    return name;
}

void Record::setName(const std::string &newName)
{
    name = newName;
}

const std::string &Record::getSurname() const
{
    return surname;
}

void Record::setSurname(const std::string &newSurname)
{
    surname = newSurname;
}

double Record::getValue() const
{
    return value;
}

void Record::setValue(double newValue)
{
    value = newValue;
}

Record::~Record()
{
    // Destructor implementation if needed
}