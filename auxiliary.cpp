/*
    auxiliary.cpp
    COSC 220-750 Project 2
    implementation file for auxiliary.h

    Lauren Taylor
    Created: 31 March 2021
    Current: 3 April 2021
*/

#include "auxiliary.h"
#include <iterator>
#include <cctype>

// prints options of container types to choose from
void print_container_menu() {
    cout << "Which container would you like to test?" << endl << endl;
    cout << "Type 1 to test a stack container" << endl;
    cout << "Type 2 to test a queue container" << endl << endl;
    cout << "Enter 1 or 2: ";
}

// prompt user to choose a queue or stack container, return choice
string get_container_choice() {
    string choice = "";

    do {
        print_container_menu();
        cin >> choice;
        cout << endl << endl;

        if (choice != "1" && choice != "2")
            cout << "Invalid selection. Please enter 1 or 2.\n\n";

    } while (choice != "1" && choice != "2");

    return choice; 
}

// prints options of container methods to choose from
void print_container_type_menu() {
    cout << "Which container implementation method would you like to test?\n\n";
    cout << "Type 1 to test the container using STL vector\n";
    cout << "Type 2 to test the container using a dynamic array\n";
    cout << "Type 3 to test the container using STL list\n";
    cout << "Type 4 to test the container using a doubly linked list\n\n";
    cout << "Enter 1, 2, 3, or 4: ";
}

// prompt user to choose vector, dynamic array, doubly linked list, or list,
// return choice
string get_container_type() {
    string choice = "";

    do {
        print_container_type_menu();
        cin >> choice;
        cout << endl << endl;

        if (choice < "1" || choice > "4")
            cout << "Invalid selection. Please enter 1, 2, 3, or 4.\n\n";

    } while (choice < "1" || choice > "4");

    return choice;
}

// print options for manipulating a stack container
void print_stack_menu() {
    cout << "Stack container options are:" << endl << endl;
    cout << "1. push element" << endl;
    cout << "2. pop element" << endl;
    cout << "3. print all elements" << endl;
    cout << "4. print top element" << endl;
    cout << "5. print size of stack" << endl;
    cout << "6. exit" << endl << endl;
    cout << "Type 1-6: ";
}

// validate user selection and return their choice of action
string get_stack_option() {
    string ch = "";

    do {
        print_stack_menu();
        cin >> ch;
        cout << endl << endl;

        if (ch < "1" || ch > "6")
            cout << "Invalid selection." << endl << endl;
    } while (ch < "1" || ch > "6");

    return ch;
}

// stack container main interface
void make_stack(const string ch) {
    if (ch == "1") {    // option: STL vector
        make_stack_VT();

    } else if (ch == "2") {     // option: dynamic array
        make_stack_DA();

    } else if (ch == "3") {     // option: STL list
        make_stack_LT();

    } else {        // option: doubly linked list
        make_stack_DL();
    }
}

// beginning stack dynamic array process
void make_stack_DA() {
    miniStackDA<string> stack;
    string choice = "";

    do {
        string option = get_stack_option();

        if (option == "1") {    // push element
            stack.Push(get_new_stack_element());
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "2") {     // pop element
            stack.Pop();
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "4") {     // print top element
            cout << "The top element is: ";
            cout << stack.TopStack() << endl << endl;

        } else if (option == "5") {        // print size of stack
            cout << "The stack size is: ";
            cout << stack.size() << endl << endl;

        } else {
            return;
        }
    } while (choice != "6");
}

// beginning stack doubly linked list process
void make_stack_DL() {
    miniStackDL<string> stack;
    string choice = "";

    do {
        string option = get_stack_option();

        if (option == "1") {    // push element
            stack.Push(get_new_stack_element());
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "2") {     // pop element
            stack.Pop();
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "4") {     // print top element
            cout << "The top element is: ";
            cout << stack.TopStack() << endl << endl;

        } else if (option == "5") {        // print size of stack
            cout << "The stack size is: ";
            cout << stack.size() << endl << endl;

        } else {
            return;
        }
    } while (choice != "6");
}

// beginning stack STL list process
void make_stack_LT() {
    miniStackLT<string> stack;
    string choice = "";

    do {
        string option = get_stack_option();

        if (option == "1") {    // push element
            stack.Push(get_new_stack_element());
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "2") {     // pop element
            stack.Pop();
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "4") {     // print top element
            cout << "The top element is: ";
            cout << stack.TopStack() << endl << endl;

        } else if (option == "5") {        // print size of stack
            cout << "The stack size is: ";
            cout << stack.size() << endl << endl;

        } else {
            return;
        }
    } while (choice != "6");
}

// beginning stack STL vector process
void make_stack_VT() {
    miniStackVT<string> stack;
    string choice = "";

    do {
        string option = get_stack_option();

        if (option == "1") {    // push element
            stack.Push(get_new_stack_element());
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "2") {     // pop element
            stack.Pop();
            cout << "The stack now contains:\n\n";
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            stack.PrintStack();
            cout << endl << endl;

        } else if (option == "4") {     // print top element
            cout << "The top element is: ";
            cout << stack.TopStack() << endl << endl;

        } else if (option == "5") {        // print size of stack
            cout << "The stack size is: ";
            cout << stack.size() << endl << endl << endl;

        } else {
            return;
        }
    } while (choice != "6");
}

// get element to add to stack from user
string get_new_stack_element() {
    string value;

    do {
        cout << "Enter the element you wish to add to the stack: ";
        cin >> value;
        cout << endl << endl;

        for (int i = 0; i < value.length(); i++) {
            if (!isprint(value[i])) {
                cout << "Invalid entry. One or more character is unprintable";
                cout << endl << endl;

                value = "";
            }
        }

    } while (value == "");

    return value;
}

// print options for manipulating a queue container
void print_queue_menu() {
    cout << "Queue container options are:" << endl << endl;
    cout << "1. enqueue element" << endl;
    cout << "2. dequeue element" << endl;
    cout << "3. print all elements" << endl;
    cout << "4. print front element" << endl;
    cout << "5. print size of queue" << endl;
    cout << "6. exit" << endl << endl;
    cout << "Type 1-6: ";
}

// validate user selection and return their choice of action
string get_queue_option() {
    string ch = "";

    do {
        print_queue_menu();
        cin >> ch;
        cout << endl << endl;

        if (ch < "1" || ch > "6")
            cout << "Invalid selection." << endl << endl;
    } while (ch < "1" || ch > "6");

    return ch;
}

// queue container main interface
void make_queue(const string ch) {
    if (ch == "1") {    // option: STL vector
        make_queue_VT();

    } else if (ch == "2") {     // option: dynamic array
        make_queue_DA();

    } else if (ch == "3") {     // option: STL list
        make_queue_LT();

    } else {        // option: doubly linked list
        make_queue_DL();
    }
}

// beginning queue dynamic array process
void make_queue_DA() {
    miniQueueDA<string> queue;
    string again = "";

    do {
        string option = get_queue_option();

        if (option == "1") {    // enqueue
            queue.enqueue(get_new_queue_element());
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "2") {     // dequeue
            queue.dequeue();
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "4") {     // print front element
            cout << "The front element is: ";
            cout << queue.front() << endl << endl << endl;

        } else if (option == "5") {        // print size of queue
            cout << "The size of the queue is: ";
            cout << queue.size();
            cout << endl << endl << endl;

        } else {
            return;
        }

    } while (again != "6");
}

// beginning queue doubly linked list process
void make_queue_DL() {
    miniQueueDL<string> queue;
    string again = "";

    do {
        string option = get_queue_option();

        if (option == "1") {    // enqueue
            queue.enqueue(get_new_queue_element());
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "2") {     // dequeue
            queue.dequeue();
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "4") {     // print front element
            cout << "The front element is: ";
            cout << queue.front() << endl << endl << endl;

        } else if (option == "5") {        // print size of queue
            cout << "The size of the queue is: ";
            cout << queue.size();
            cout << endl << endl << endl;

        } else {
            return;
        }

    } while (again != "6");
}

// beginning queue STL list process
void make_queue_LT() {
    miniQueueLT<string> queue;
    string again = "";

    do {
        string option = get_queue_option();

        if (option == "1") {    // enqueue
            queue.enqueue(get_new_queue_element());
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "2") {     // dequeue
            queue.dequeue();
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "4") {     // print front element
            cout << "The front element is: ";
            cout << queue.front() << endl << endl << endl;

        } else if (option == "5") {        // print size of queue
            cout << "The size of the queue is: ";
            cout << queue.size();
            cout << endl << endl << endl;

        } else {
            return;
        }

    } while (again != "6");
}

// beginning queue STL vector process
void make_queue_VT() {
    miniQueueVT<string> queue;
    string again = "";

    do {
        string option = get_queue_option();

        if (option == "1") {    // enqueue
            queue.enqueue(get_new_queue_element());
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "2") {     // dequeue
            queue.dequeue();
            cout << "The queue now contains:\n\n";
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "3") {     // print all elements
            queue.PrintQueue();
            cout << endl << endl;

        } else if (option == "4") {     // print front element
            cout << "The front element is: ";
            cout << queue.front() << endl << endl << endl;

        } else if (option == "5") {        // print size of queue
            cout << "The size of the queue is: ";
            cout << queue.size();
            cout << endl << endl << endl;

        } else {
            return;
        }

    } while (again != "6");
}

// get element to add to queue from user
string get_new_queue_element() {
    string value = "";

    do {
        cout << "Enter the element you wish to add to the queue: ";
        cin >> value;
        cout << endl << endl;

        for (int i = 0; i < value.length(); i++) {
            if (!isprint(value[i])) {
                cout << "Error: entry unprintable";
                cout << endl << endl;

                value = "";
            }
        }

    } while (value == "");

    return value;
}