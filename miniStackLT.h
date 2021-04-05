/*
    miniStackLT.h
    COSC 220-750 Project 2
    definition of class miniStackLT
    a miniStack implemented using STL <list>

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#ifndef MINISTACKLT_H
#define MINISTACKLT_H

#include <list>
using std::list;
#include <iostream>
#include <iterator>

template <class DataType>
class miniStackLT {
    private:
        list<DataType> content;
        int elementCount;   // number of elements in stack

    public:
        // constructor creates a stack with size zero
        miniStackLT();

        // destructor
        ~miniStackLT();
        
        // returns the number of elements in the stack
        int size() const;

        // check if stack is empty
        bool IsEmpty() const;

        // push an element in the stack
        void Push(const DataType &);

        // print all stack content (top to bottom)
        void PrintStack() const;

        // pop an element from top of stack, issue exception if stack is empty
        void Pop();

        // return data from top of the stack, issue exception if stack is empty
        DataType& TopStack();

        // return constant data from top of stack, issue exception if stack is empty
        const DataType& TopStack() const;
        
};

#include "miniStackLT.cpp"
#endif /* miniStackLT.h */