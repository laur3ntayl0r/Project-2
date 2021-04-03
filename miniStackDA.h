/*
    miniStackDA.h
    COSC 220-750 Project 2
    definition of class miniStackDA
    a miniStack implemented using dynamic array

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#ifndef MINISTACKDA_H
#define MINISTACKDA_H

template <class DataType>
class miniStackDA {
    private:
        DataType *content;
        int elementCount;   // number of elements in stack

    public:
        // constructor creates a stack with size zero
        miniStackDA();

        // destructor
        ~miniStackDA();

        // returns the number of elements in the stack
        int size() const;

        // return true if stack is empty, else false
        bool IsEmpty() const;

        // push an element in the stack
        void Push(const DataType &);

        // print all stack content (top to bottom), issue exception if stack is empty
        void PrintStack() const;

        // pop top element in stack, issue exception if stack is empty
        void Pop();

        // return top element in stack, issue exception if stack is empty
        DataType& TopStack();

        // return top element in stack, issue exception if stack is empty
        const DataType& TopStack() const;
        
};

#include "miniStackDA.cpp"
#endif /* miniStackDA.h */