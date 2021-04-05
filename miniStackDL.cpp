/*
    miniStackDL.cpp
    COSC 220-750 Project 2
    implementation file for miniStackDL.h
    a miniStack implemented using doubly linked list

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#include "miniStackDL.h"
#include <iostream>
using namespace std;

// constructor creates a stack with size zero
template <class T>
miniStackDL<T>::miniStackDL() {
    elementCount = 0;
    head = NULL;
    tail = NULL;
}

// destructor
template <class T>
miniStackDL<T>::~miniStackDL() {
    DNode<T> *curr = head;

    while (curr != NULL) {
        delete head;
        head = curr = curr->next;
    }
}

// returns the number of elements in the stack
template <class T>
int miniStackDL<T>::size() const {
    return elementCount;
}

// return true if stack is empty, else false
template <class T>
bool miniStackDL<T>::IsEmpty() const {
    return head == NULL ? true : false;
}

// push a node on top of the stack
template <class T>
void miniStackDL<T>::Push(const T &value) {
    // if stack is empty create head node with nodeValue = value
    if (IsEmpty()) {
        head = new DNode<T>(value);

        tail = head;
    
    } else {
        // create new node with nodeValue = value and prev = tail
        DNode<T> *newNode = new DNode<T>(value, tail);

        // last node now points to a new last node
        tail->next = newNode;

        // tail now points to the new last node
        tail = tail->next;
    }

    // increment number of elements by 1
    ++elementCount;
}

// print all stack content (top to bottom), issue exception if empty
template <class T>
void miniStackDL<T>::PrintStack() const {
    if (IsEmpty())
        cout << "stack empty";

    else {
        // create node to keep track of current node
        DNode<T> *curr = tail;

        cout << "(top) ";

        // cycle through until last node is printed
        while (curr != NULL) {
            cout << curr->nodeValue << " ";
            curr = curr->prev;
        }
    }

    cout << endl << endl;
}

// pop an element from top of stack, issue exception if stack is empty
template <class T>
void miniStackDL<T>::Pop() {
    // throwing exception if stack is empty
    if (IsEmpty())
        throw underflow_error("stack empty");

    else if (head == tail) {    // if stack only contains 1 element, make
        tail = NULL;            // both head and tail nodes point to NULL
        head = NULL;

    } else {
        // assign tail to point to its previous node
        tail = tail->prev;

        // delete the last node 
        delete tail->next;

        // have tail point to NULL, since it is the last node
        tail->next = NULL;
    }

    // decrementing number of elements by 1
    --elementCount;
}

// return data from top of the stack, issue exception if stack is empty
template <class T>
T& miniStackDL<T>::TopStack() {
    if (IsEmpty())
        throw underflow_error("stack empty");
    else
        return tail->nodeValue;
}

// return constant data from top of the stack, issue exception if stack is empty
template <class T>
const T& miniStackDL<T>::TopStack() const {
    if (IsEmpty())
        throw underflow_error("stack empty");
    else
     return tail->nodeValue;
}