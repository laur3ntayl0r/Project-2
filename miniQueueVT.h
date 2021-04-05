/*
    miniQueueVT.h
    COSC 220-750 Project 2
    definition of class miniQueueVT
    a miniQueue implemented using STL <vector>

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#ifndef MINIQUEUEVT_H
#define MINIQUEUEVT_H

#include <vector>
using std::vector;

template <class DataType>
class miniQueueVT {
    private:
        vector<DataType> content;
        int elementCount;   // number of elements in queue

    public:
        // class constructor - queue size set to zero
        miniQueueVT();

        // class destructor - return memory used by queue elements
        ~miniQueueVT();

        // add an item to back of queue
        void enqueue(const DataType &);

        // remove front element in queue & return its value, issue exception if empty
        void dequeue();

        // return front element in queue, issue exception if empty
        DataType& front();

        // return front element in queue, issue exception if empty
        const DataType& front() const;

        // print all queue content (front to back)
        void PrintQueue() const;

        // returns true if the queue is empty
        bool IsEmpty() const;

        // returns the number of elements in the queue
        int size() const;
};

#include "miniQueueVT.cpp"
#endif /* miniQueueVT.hpp */