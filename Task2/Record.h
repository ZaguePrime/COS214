#ifndef RECORD_H
#define RECORD_H

#include <string>


class Record
{
private:
    static int keyCounter;
    int key;
    std::string name;
    std::string surname;
    double value;

public:

    enum field{
        KEY,
        NAME,
        SURNAME,
        VALUE
    };


    Record();
    Record(int key, std::string name, std::string surname, double value);
    int getKey() const;
    void setKey(int newKey){this->key = newKey;};
    const std::string &getName() const;
    void setName(const std::string &newName);
    const std::string &getSurname() const;
    void setSurname(const std::string &newSurname);
    double getValue() const;
    void setValue(double newValue);

    bool update();
    
    std::string to_string();

    ~Record();
};

#endif