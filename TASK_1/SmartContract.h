#ifndef SMART_C_H
#define SMART_C_H
#include <string>
#include <vector>

class State;

class SmartContract//
{
private:
    /* data */
    int numCompleted;
    State* state;
    int numParties;
    std::vector<std::string> conditions;
    int acceptedParties;
    std::string name;
public:
    SmartContract(/* args */);
    SmartContract(int, std::string);//done
    void addCondition(std::string);//done
    void removeCondition(int);//done
    void acceptContract();//done
    void rejectContract();//done
    void completeContract();//done
    void changeState();//done
    void setState(State*);//done
    std::vector<std::string>* getConditions();//done
    int getAcceptedParties();//done
    void acceptance();//done
    int getNumParties();//done
    int getCompleted();//done
    void complete();
    void reset();
    ~SmartContract();//done
    std::string toString();
};


#endif