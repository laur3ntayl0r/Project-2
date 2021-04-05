/*
    miniStackDA.cpp
    COSC 220-750 Project 2
    implementation file for miniStackDA.h
    a miniStack implemented using dynamic array

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#include "miniStackDA.h"
#include <iostream>
using namespace std;


// constructor creates a stack with size 0
template <class DataType>
miniStackDA<DataType>::miniStackDA() {
    content = NULL;
    elementCount = 0;
}

// destructor
template <class DataType>
miniStackDA<DataType>::~miniStackDA() {
    if (!IsEmpty())
        delete [] content;
}

// returns number of elements in the stack
template <class DataType>
int miniStackDA<DataType>::size() const {
    return elementCount;
}

// returns true if stack is empty, else false
template <class DataType>
bool miniStackDA<DataType>::IsEmpty() const {
    return elementCount == 0 ? true : false;
}

// push an element in the stack
template <class DataType>
void miniStackDA<DataType>::Push(const DataType &value) {
    if (IsEmpty()) {
        content = new DataType[1];
        content[0] = value;

    } else {
        // creating a new dynamic array of DataType with 1 more element
        DataType *newStack = new DataType[elementCount + 1];

        // copying over every element from old stack
        for (int i = 0; i < elementCount; i++)
                newStack[i] = content[i];

        // last element in new stack is assigned to value
        newStack[elementCount] = value;

        // freeing memory allocated for content
        delete [] content;

        // making content point to newStack
        content = newStack;
    }

    // incrementing number of elements by 1
    ++elementCount;
}

// print all stack content (top to bottom), issue exception if stack is empty
template <class DataType>
void miniStackDA<DataType>::PrintStack() const {
    if (IsEmpty())
        cout << "stack empty";

    else {
        cout << "(top) ";

        for (int i = elementCount - 1; i >= 0; i--)
            cout << content[i] << " ";
    }

    cout << endl << endl;
}

// pop top element in stack, issue exception if stack is empty
template <class DataType>
void miniStackDA<DataType>::Pop() {
    if (IsEmpty()) {
        throw underflow_error("stack empty");

    } else if (elementCount == 1) {
        content = NULL;

    } else {
        // creating a new dynamic array of DataType with 1 less element
        DataType *newStack = new DataType[elementCount - 1];

        // copying over everything except last element (i.e., top element)
        for (int i = 0; i < elementCount - 1; i++)
            newStack[i] = content[i];

        // freeing memory allocated to content
        delete [] content;

        // making content point to newStack
        content = newStack;
    }

    // decrementing number of elements by 1
    --elementCount;
}

// return top element in stack, issue exception if stack is empty
template <class DataType>
DataType& miniStackDA<DataType>::TopStack() {
    if (IsEmpty())
        throw underflow_error("stack empty");

    return content[elementCount - 1];
}

// return top element in stack, issue exception if stack is empty
template <class DataType>
const DataType& miniStackDA<DataType>::TopStack() const {
    if (IsEmpty())
        throw underflow_error("stack empty");

    return content[elementCount - 1];
}