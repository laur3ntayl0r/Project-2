/*
    auxiliary.h
    COSC 220-750 Project 2
    auxiliary function prototypes for manipulating a stack or queue container

    Lauren Taylor
    Created: 31 March 2021
    Current: 5 April 2021
*/

#ifndef AUXILIARY_H
#define AUXILIARY_H

// including header files (which include .cpp files) for miniStacks
#include "miniStackVT.h"
#include "miniStackDA.h"
#include "miniStackLT.h"
#include "miniStackDL.h"

// including header files (which include .cpp files) for miniQueues
#include "miniQueueVT.h"
#include "miniQueueDA.h"
#include "miniQueueLT.h"
#include "miniQueueDL.h"

// include class DNode for doubly linked lists
#include "DNode.h"

// other includes
#include <string>
using std::string;
#include <exception>


// prints options of container types to choose from
void print_container_menu();

// prompt user to choose a queue or stack container, return choice
string get_container_choice();

// prints options of container methods to choose from
void print_implement_type_menu();

// prompt user to choose vector, dynamic array, doubly linked list, or list,
// return choice
string get_implement_type();

// print options for manipulating a stack container
void print_stack_menu();

// validate user selection and return their choice of action
string get_stack_option();

// beginning stack container selection process
void make_stack(const string);

// performs manipulation and printing functions for stacks
template <class DataType>
void perform_stack_options(DataType &);

// get element to add to stack from user
string get_new_stack_element();

// print options for manipulating a queue container
void print_queue_menu();

// validate user selection and return their choice of action
string get_queue_option();

// beginning queue container selection process
void make_queue(const string);

// performs manipulation and printing functions for queues
template <class DataType>
void perform_queue_options(DataType &);

// beginning queue dynamic array process
void make_queue_DA();

// beginning queue doubly linked list process
void make_queue_DL();

// beginning queue STL list process
void make_queue_LT();

// beginning queue STL vector process
void make_queue_VT();

// get element to add to queue from user
string get_new_queue_element();


#endif  /* auxiliary.h */
