#include "acceptedState.h"
#include "completeState.h"
#include "SmartContract.h"

void acceptedState::addCondition(SmartContract* c, std::string condition) {
    throw Exception("Illegal action", "You cannot add a condition, the contract has been accepted");
}

void acceptedState::removeCondition(SmartContract* c, int conditionIndex) {
    throw Exception("Illegal action", "You cannot remove a condition, the contract has been accepted");
}
//
void acceptedState::acceptContract(SmartContract* c) {
    throw Exception("Illegal action", "You cannot accept the contract, the contract has been accepted");
}

void acceptedState::rejectContract(SmartContract* c) {
    throw Exception("Illegal action", "You cannot reject the contract, the contract has been accepted");
}


void acceptedState::completeContract(SmartContract* c) {
    // Implement completeContract function
    // Update the state of the SmartContract object to "completed"
    c->complete();
    c->changeState();
}

void acceptedState::handleChange(SmartContract* c) {
    // Implement handleChange function
    // Handle any necessary changes or actions when the state of the SmartContract changes
    int numC = c->getCompleted();
    int numP = c->getNumParties();
    if(numC==numP)
    {
        c->setState(new completeState());
        return;
    }
    c->setState(new acceptedState);
}

std::string acceptedState::getState()
{
    return "Accepted";
}