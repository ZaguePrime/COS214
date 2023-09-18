#ifndef A_STATE_H
#define A_STATE_H
#include "State.h"
#include "Exception.h"//
class acceptedState:public State
{
private:
    /* data */
public:
    void addCondition(SmartContract* c,std::string) override;
    void removeCondition(SmartContract* c, int) override;
    void acceptContract(SmartContract* c) override;
    void rejectContract(SmartContract* c) override;
    void completeContract(SmartContract* c) override;
    void handleChange(SmartContract* c) override;
    std::string getState() override;
};

#endif
