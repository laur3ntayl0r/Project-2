/*
    miniQueueDL.h
    COSC 220-750 Project 2
    defintion of class miniQueueDL
    a miniQueue implemented using doubly linked list

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#ifndef MINIQUEUEDL_H
#define MINIQUEUEDL_H

#include "DNode.h"

template <class T>
class miniQueueDL {
    private:
        DNode<T>* head;     // to keep track of head node
        DNode<T>* tail;     // to keep track of last node
        int elementCount;   // number of elements in queue

    public:
        // class constructor - queue size set to zero
        miniQueueDL();

        // class destructor - return memory used by queue elements
        ~miniQueueDL();

        // add an item to back of queue
        void enqueue(const T &);

        // remove first item from queue & return its value, issue exception if empty
        void dequeue();

        // return value of queue's front element, issue exception if empty
        T& front();

        // return constant value of queue's front element, issue exception if emtpy
        const T& front() const;

        // print all queue elements (front to back)
        void PrintQueue() const;

        // returns true if the queue is empty
        bool IsEmpty() const;

        // returns the number of elements in the queue
        int size() const;
};

#include "miniQueueDL.cpp"
#endif /* miniQueueDL.h */