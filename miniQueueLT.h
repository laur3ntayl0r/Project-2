/*
    miniQueueLT.hpp
    COSC 220-750 Project 2
    definition of class miniQueueLT
    a miniQueue implemented using STL <list>

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#ifndef MINIQUEUELT_H
#define MINIQUEUELT_H

#include <list>
using std::list;

template <class DataType>
class miniQueueLT {
    private:
        list<DataType> content;
        int elementCount;   // number of elements in queue

    public:
        // class constructor - queue size set to zero
        miniQueueLT();

        // class destructor - return memory used by queue elements
        ~miniQueueLT();

        // add an item to back of queue
        void enqueue(const DataType &);

        // remove front item of queue and return its value, issue exception if empty
        void dequeue();

        // return front item of queue, issue exception if empty
        DataType& front();

        // return constant front item of queue, issue exception if empty
        const DataType& front() const;

        // print all queue content (front to back), issue exception if empty
        void PrintQueue() const;

        // return true if queue is empty
        bool IsEmpty() const;
        
        // returns the number of elements in the queue
        int size() const;
        
};

#include "miniQueueLT.cpp"
#endif /* miniQueueLT.h */