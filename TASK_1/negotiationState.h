#ifndef N_STATE_H
#define N_STATE_H
#include "State.h"
#include "Exception.h"//
class negotiationState: public State
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


