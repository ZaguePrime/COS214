#ifndef STATE_H
#define STATE_H
#include <string>

class SmartContract;

class State
{

protected:
    bool reject = false;
private:
    /* data */
public:
    virtual void addCondition(SmartContract*,std::string) = 0;
    virtual void removeCondition(SmartContract*, int) = 0;
    virtual void acceptContract(SmartContract*) = 0;//
    virtual void rejectContract(SmartContract*) = 0;
    virtual void completeContract(SmartContract*) = 0;
    virtual void handleChange(SmartContract*) = 0;
    virtual std::string getState() = 0;
};

#endif
