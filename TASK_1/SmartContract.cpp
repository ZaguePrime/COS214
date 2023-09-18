#pragma once
#include "SmartContract.h"
#include "State.h"

SmartContract::SmartContract(/* args */)
{

}

SmartContract::~SmartContract()
{
    delete state;
}

SmartContract::SmartContract(int n, std::string name)
{
    numParties = n;
    this->name = name;
}

void SmartContract::addCondition(std::string cond)
{
    state->addCondition(this,cond);
}

void SmartContract::removeCondition(int c)
{
    state->removeCondition(this,c);
}

void SmartContract::acceptContract()
{
    state->acceptContract(this);
}

void SmartContract::rejectContract()
{
    state->rejectContract(this);
}

void SmartContract::completeContract()
{
    state->completeContract(this);
}

void SmartContract::changeState()
{
    state->handleChange(this);
}

std::vector<std::string>* SmartContract::getConditions()
{
    return &conditions;
}

void SmartContract::setState(State* newState)
{
    delete state;
    state = newState;
}

int SmartContract::getAcceptedParties()
{
    return acceptedParties;
}

void SmartContract::acceptance()
{
    acceptedParties++;
}

int SmartContract::getNumParties()
{
    return numParties;
}

int SmartContract::getCompleted()
{
    return numCompleted;
}

void SmartContract::complete()
{
    numCompleted++;
}

void SmartContract::reset()
{
    acceptedParties = 0;
}

std::string SmartContract::toString()//
{
    std::string out = "";
    std::string votes = "";
    if(state->getState() == "Accepted" || state->getState() == "Tentatively accepted")
    {
        votes = "Votes:\n"+std::to_string(acceptedParties)+"/"+std::to_string(numParties);
    }
    out+= "Contract "+name+":\n";
    out+= votes+"\n"+
    +"\tState: "+state->getState()+"\n"
    +"\tConditions:\n";

    for(size_t i = 0; i < conditions.size(); i++)
        out+="\t\t"+std::to_string(i+1)+"."+conditions[i]+"\n";
    
    return out;
}

