/*
    miniQueueDA.cpp
    COSC 220-750 Project 2
    implementation file for miniQueueDA.h
    a miniQueue implemented using dynamic array

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#include "miniQueueDA.h"
#include <iostream>
using namespace std;

// default constructor
template <class DataType>
miniQueueDA<DataType>::miniQueueDA() {
    content = NULL;
    elementCount = 0;
}

// destructor
template <class DataType>
miniQueueDA<DataType>::~miniQueueDA() {
    if (!IsEmpty())
        delete [] content;
}

// add an item to back of queue
template <class DataType>
void miniQueueDA<DataType>::enqueue(const DataType &value) {
    // if queue is empty, create new array of 1 DataType, and 
    // assign it to value
    if (IsEmpty()) {
        content = new DataType[1];
        content[0] = value;

    } else {
        // create a new queue with 1 more element
        DataType *newQueue = new DataType[elementCount + 1];

        // copy the elements of old queue into new queue
        for (int i = 0; i < elementCount; i++) {
            newQueue[i] = content[i];
        }

        // assign last element to value
        newQueue[elementCount] = value;

        // free memory allocated for content
        delete [] content;

        // make content point to the array newQueue points to
        content = newQueue;
    }
    
    // increment number of elements by 1
    ++elementCount;
}

// remove front item from queue & return its value, issue exception if empty
template <class DataType>
void miniQueueDA<DataType>::dequeue() {
    // throw exception if queue is empty
    if (IsEmpty())
        throw underflow_error("queue empty");

    // create new queue with 1 less element
    DataType *newQueue = new DataType[elementCount - 1];

    // copy over every element except first
    for (int i = 0; i < elementCount - 1; i++) {
        for (int j = 1; j < elementCount; j++)
            newQueue[i] = content[j];
    }

    // free memory allocated for content
    delete [] content;

    // make content point to the dynamic array pointed to by newQueue
    content = newQueue;

    // decrement number of elements by 1
    --elementCount;
}

template <class DataType>
DataType& miniQueueDA<DataType>::front() {
    if (IsEmpty())
        throw underflow_error("queue empty");

    return *content;
}

template <class DataType>
const DataType& miniQueueDA<DataType>::front() const {
    if (IsEmpty())
        throw underflow_error("queue empty");
    
    return *content;
}

template <class DataType>
void miniQueueDA<DataType>::PrintQueue() const {
    if (IsEmpty())
        cout << "queue empty";

    else {
        cout << "(front)\t";

        for (int i = 0; i < elementCount; i++)
            cout << content[i] << " ";
        
        cout << "\t(back)";
    }

    cout << endl << endl;
}

template <class DataType>
bool miniQueueDA<DataType>::IsEmpty() const {
    return elementCount == 0 ? true : false;
}

template <class DataType>
int miniQueueDA<DataType>::size() const {
    return elementCount;
}