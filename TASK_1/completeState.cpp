#include "completeState.h" // Include necessary header file(s)
#include "SmartContract.h"
//
void completeState::addCondition(SmartContract* c, std::string condition) {
    throw Exception("Illegal action", "You cannot add a condition, the contract is already complete");
}

void completeState::removeCondition(SmartContract* c, int conditionIndex) {
    throw Exception("Illegal action", "You cannot remove a condition, the contract is already complete");
}

void completeState::acceptContract(SmartContract* c) {
    throw Exception("Illegal action", "You cannot add a condition, the contract is already complete");
}

void completeState::rejectContract(SmartContract* c) {
    throw Exception("Illegal action", "You cannot accept the contract, the contract is already complete");
}

void completeState::completeContract(SmartContract* c) {
    throw Exception("Illegal action", "You cannot complete the contract, the contract is already complete");
}

void completeState::handleChange(SmartContract* c) {
    throw Exception("Illegal action", "You cannot state change, the contract is already complete");
}

std::string completeState::getState() {
    return "Completed"; // Update this based on the actual state
}
