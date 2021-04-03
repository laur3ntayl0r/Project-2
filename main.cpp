/*
    main.cpp
    COSC 220-750 Project 2
    driver program with menu options for users to test all containers; users will be
    able to:
        - add/remove elements to/from a container
        - display content and size of a container
        - display value of front or top element in a container

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#include "auxiliary.h"
#include <iostream>
using namespace std;

int main() {
    string again = "";

    cout << endl;

    do {
        string choice = get_container_choice();

        string choice2 = get_implement_type();

        choice == "1" ? make_stack(choice2) : make_queue(choice2);

        cout << "Would you like to test another container?\n\n";
        cout << "Type 1 to create a new container, 2 to exit: ";
        cin >> again;
        cout << endl << endl;

    } while (again == "1");

    cout << endl << "Goodbye!" << endl << endl;

    return 0;
}
