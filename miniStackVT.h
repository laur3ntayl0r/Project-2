/*
    miniStackVT.h
    COSC 220-750 Project 2
    definition of class miniStackVT
    a miniStack implemented using STL <vector>

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#ifndef MINISTACKVT_H
#define MINISTACKVT_H

#include <vector>
using std::vector;

template <class DataType>
class miniStackVT {
    private:
        vector<DataType> content;
        int elementCount;   // number of elements in stack

    public:
        // constructor creates a stack with size zero
        miniStackVT();

        // destructor
        ~miniStackVT();

        // returns the number of elements in the stack
        int size() const;

        // check if stack is empty
        bool IsEmpty() const;

        // push a value in the stack
        void Push(const DataType &);

        // print all stack content (top to bottom)
        void PrintStack() const;

        // pop an element from top of stack, issue exception if stack is empty
        void Pop();

        // return data from top of the stack, issue exception if stack is empty
        DataType& TopStack();

        // return data from top of stack, issue exception if stack is empty
        const DataType& TopStack() const;

};

#include "miniStackVT.cpp"
#endif /* miniStackVT.h */