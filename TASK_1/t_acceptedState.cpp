#include "t_acceptedState.h"
#include "negotiationState.h"
#include "acceptedState.h"
#include "rejectedState.h"
#include "SmartContract.h"
#include <iostream>

void t_acceptedState::addCondition(SmartContract* c, std::string condition)
{
    if(condition.empty()) return;
    c->getConditions()->push_back(condition);
    ar = true;
    c->reset();
    std::cout<<"Condition added"<<std::endl;
    c->changeState();
}

void t_acceptedState::removeCondition(SmartContract* c, int x)
{
    int size = c->getConditions()->size();
    if(x-1>=size) return;//to throw exception
    ar = true;
    c->reset();
    c->getConditions()->erase(c->getConditions()->begin()+(x-1));//erase at given position
    std::cout<<"Condition "<<x<<" has been removed"<<std::endl;
    c->changeState();
}

void t_acceptedState::acceptContract(SmartContract* c)
{
    c->acceptance();
    c->changeState();
}
//
void t_acceptedState::rejectContract(SmartContract* c)
{
    reject = true;
    c->changeState();
}

void t_acceptedState::completeContract(SmartContract* c)
{
    throw new Exception("Illegal action","You cannot complete the contract, the contract has not been fully accepted");
}

void t_acceptedState::handleChange(SmartContract* c)
{
    if(reject)
    {
        reject = false;
        c->setState(new rejectedState());
        return;
    }
    int numA = c->getAcceptedParties();
    int numP = c->getNumParties();

    if(ar)
    {
        ar=false;
        c->setState(new negotiationState());
        return;
    }

    if(numA == numP)
    {
        c->setState(new acceptedState());
        return;
    }
    c->setState(new t_acceptedState());
}

std::string t_acceptedState::getState()
{
    return "Tentatively accepted";
}