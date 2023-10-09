// Record.cpp
#include "Record.h"

int Record::keyCounter = 0;

Record::Record() : key(keyCounter++)
{
    name = "";
    surname = "";
    value = 0.0;
}

Record::Record(int key, std::string name, std::string surname, double value)
{
    this->key = key;
    this->name = name;
    this->surname = surname;
    this->value = value;
}


int Record::getKey() const
{
    return key;
}

void Record::setKey(int newKey)
{
    this->key = newKey;
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

std::string Record::to_string(){
    return "{key:"+ std::to_string(key) +" name:"+ name +" surname:"+ surname+" value:"+ std::to_string(value)+"}";
}

Record::~Record()
{
    // Destructor implementation if needed
}