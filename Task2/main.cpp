#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Database db;

    cout<<db.databaseQuery("select * from people")<<endl<<endl;

    return 0;
}