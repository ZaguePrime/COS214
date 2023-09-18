#ifndef T_ACC_H
#define T_ACC_H
#include "State.h"
#include "Exception.h"
class t_acceptedState:public State
{
private:
    /* data */
    bool ar = false;
public:
    void addCondition(SmartContract*,std::string) override;//done
    void removeCondition(SmartContract*,int) override;//done
    void acceptContract(SmartContract*) override;//done
    void rejectContract(SmartContract*) override;//done
    void completeContract(SmartContract*) override;
    void handleChange(SmartContract*) override;//done
    std::string getState() override;
};

#endif