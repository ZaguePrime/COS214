#include "rejectedState.h"

void rejectedState::addCondition(SmartContract* c, std::string condition) {
        throw Exception("Illegal action", "You cannot add a condition, the contract has been rejected");//
}

void rejectedState::removeCondition(SmartContract* c, int conditionIndex) {
        throw Exception("Illegal action", "You cannot remove a condition, the contract has been rejected");
}

void rejectedState::acceptContract(SmartContract* c) {
        throw Exception("Illegal action", "You cannot accept the contract, the contract has been rejected");
}

void rejectedState::rejectContract(SmartContract* c) {
        throw Exception("Illegal action", "You cannot reject the contract, the contract has been rejected");
}

void rejectedState::completeContract(SmartContract* c) {
        throw Exception("Illegal action", "You cannot complete the contract, the contract has been rejected");
}

void rejectedState::handleChange(SmartContract* c) {
        throw Exception("Illegal action", "You cannot change state, the contract has been rejected");
}

std::string rejectedState::getState() {
    // Implement getState function
    // Return the current state of the SmartContract as a string
    return "Rejected"; // Update this based on the actual state
}