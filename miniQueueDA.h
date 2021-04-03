/*
    miniQueueDA.h
    COSC 220-750 Project 2
    definition of class miniQueueDA
    a miniQueue implemented using dynamic array

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#ifndef MINIQUEUEDA_H
#define MINIQUEUEDA_H

template <class DataType>
class miniQueueDA {
    private:
        DataType *content;
        int elementCount;   // number of elements in queue

    public:
        // class constructor - queue size set to zero
        miniQueueDA();

        // class destructor - return memory used by queue elements
        ~miniQueueDA();

        // add an item to back of queue
        void enqueue(const DataType &);

        // remove front item from queue, issue exception if empty
        void dequeue();

        // return value of front element in queue, issue exception if empty
        DataType& front();

        // return constant value of front element in queue, issue exception if empty
        const DataType& front() const;

        // print all queue elements (front to back), issue exception if empty
        void PrintQueue() const;
        
        // returns true if queue is empty
        bool IsEmpty() const;

        // returns number of elements in queue
        int size() const;
        
};

#include "miniQueueDA.cpp"
#endif /* miniQueueDA.h */