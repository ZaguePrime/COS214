#include "negotiationState.h"
#include "t_acceptedState.h"
#include "rejectedState.h"
#include "SmartContract.h"
#include <iostream>

void negotiationState::addCondition(SmartContract* c, std::string condition)
{
    if(condition.empty()) return;//to throw exception
    c->getConditions()->push_back(condition);
    std::cout<<"Condition added"<<std::endl;
}

void negotiationState::removeCondition(SmartContract* c, int x)
{
    int size = c->getConditions()->size();
    if(x-1>=size) return;//to throw exception
    c->getConditions()->erase(c->getConditions()->begin()+(x-1));//erase at given position
    std::cout<<"Condition "<<x<<" has been removed"<<std::endl;
}

void negotiationState::acceptContract(SmartContract* c)
{
    c->acceptance();
    c->changeState();
}

void negotiationState::handleChange(SmartContract* c)
{
    if(reject)
    {
        std::cout<<"Switching state"<<std::endl;
        c->setState(new rejectedState());
        return;
    }
    int numP = c->getNumParties();
    int numA = c->getAcceptedParties();
    if(numA>=1)
    {
        c->setState(new t_acceptedState());//
        return;
    }
    c->setState(new negotiationState);
}

void negotiationState::rejectContract(SmartContract* c)
{
    if(c->getConditions()->empty()) return;//throw an error
    reject = true;
    c->changeState();
}

void negotiationState::completeContract(SmartContract* c)
{
    throw Exception("Illegal action","You cannot complete the contract, the contract has not been fully accepted");
}

std::string negotiationState::getState()
{
    return "Negotiation";
}