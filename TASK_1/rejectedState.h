#ifndef R_STATE_H
#define R_STATE_H//
#include "State.h"
#include "Exception.h"
class rejectedState:public State
{
private:
    /* data */
public:
    void addCondition(SmartContract*, std::string) override;//done
    void removeCondition(SmartContract*, int) override;//done
    void acceptContract(SmartContract*) override;//done
    void rejectContract(SmartContract*) override;//done
    void completeContract(SmartContract*) override;
    void handleChange(SmartContract*) override;//done
    std::string getState() override;
};


#endif
