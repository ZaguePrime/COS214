#include "Database.h"
#include <iostream>
#include <string>
#include "NewDatabase.h"

using namespace std;

void menu(NewDatabase * ndb, Database* data);

void menu2(NewDatabase * ndb, Database* data)
{
    int choice;
    std::string input;

    while (choice != 3 && choice != 2)
    {
        // Display the menu
        std::cout << "Database:\n";
        std::cout << "1. Create query\n";
        std::cout << "2. Switch to new Database query fromat\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        // Get user input
        std::getline(std::cin, input);

        // Convert input to integer
        try
        {
            choice = std::stoi(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid input. Please enter a number.\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Input out of range.\n";
            continue;
        }

        // Switch based on user choice
        switch (choice)
        {
        case 1:
            cout << "please type your query" << endl;
            std::getline(std::cin, input);
            cout<< data->databaseQuery(input)<<endl;
            break;

        case 2:
            menu(ndb,data);
            break;

        case 3:
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    }
}

void menu(NewDatabase * ndb, Database* data)
{
    int choice;
    std::string input;

    while (choice != 3 && choice != 2)
    {
        // Display the menu
        std::cout << "Database:\n";
        std::cout << "1. Create query\n";
        std::cout << "2. Switch to Legacy Database query fromat\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        // Get user input
        std::getline(std::cin, input);

        // Convert input to integer
        try
        {
            choice = std::stoi(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid input. Please enter a number.\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Input out of range.\n";
            continue;
        }

        // Switch based on user choice
        switch (choice)
        {
        case 1:
            cout << "please type your query" << endl;
            std::getline(std::cin, input);
            cout<< ndb->databaseQuery(input)<<endl;
            break;

        case 2:
            menu2(ndb,data);
            break;

        case 3:
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    }
}


int main()
{
    Database * dbs = new Database();
    NewDatabase* db = new NewDatabase(dbs);

    cout << db->databaseQuery("select * from people") << endl
         << endl;

    menu(db, dbs);

    return 0;
}
