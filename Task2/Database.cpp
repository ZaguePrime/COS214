#include "Database.h"

//public functions

// Constructor
Database::Database() {
}

std::string Database::queryHandler(std::string query) {
    return "Not implemented";
}

std::string Database::to_string() {
    return "Not implemented";
}

// Destructor
Database::~Database() {
}



//private functions
bool Database::insertRecord(Record* value) {
    return false;
}

bool Database::deleteRecord(Record* value) {
    return false;
}

std::vector<Record*> Database::selectRecord(Record* value) {
    return std::vector<Record*>();
}

bool Database::updateRecord(Record* value) {
    return false;
}

bool Database::syntaxCheck(std::string query) {
    return false;
}


