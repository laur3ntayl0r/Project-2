/*
    miniStackDL.h
    COSC 220-750 Project 2
    definition of class miniStackDL
    a miniStack implemented using doubly linked list

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#ifndef MINISTACKDL_H
#define MINISTACKDL_H

#include "DNode.h"

template <class T>
class miniStackDL {
    private:
        DNode<T>* head;
        DNode<T>* tail;
        int elementCount;   // number of elements in stack

    public:
        // constructor creates a stack with size zero
        miniStackDL();

        // destructor
        ~miniStackDL();

        // returns the number of elements in the stack
        int size() const;

        // return true if stack is empty, else false
        bool IsEmpty() const;

        // push on top of the stack
        void Push(const T &);

        // print all stack content (top to bottom), issue exception if empty
        void PrintStack() const;

        // pop an element from top of stack, issue exception if stack is empty
        void Pop();

        // return data from top of the stack, issue exception if stack is empty
        T& TopStack();

        // return data from top of stack, issue exception if stack is empty
        const T& TopStack() const;
        
};

#include "miniStackDL.cpp"
#endif /* miniStackDL.h */