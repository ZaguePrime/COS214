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

    int getKey() const;
    void setKey(int newKey);
    const std::string &getName() const;
    void setName(const std::string &newName);
    const std::string &getSurname() const;
    void setSurname(const std::string &newSurname);
    double getValue() const;
    void setValue(double newValue);

    bool update();

    ~Record();
};

#endif