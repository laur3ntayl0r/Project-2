/*
    miniQueueLT.cpp
    COSC 220-750 Project 2
    implementation file for miniQueueLT.h
    a miniQueue implemented using STL <list>

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#include "miniQueueLT.h"
#include <iostream>
#include <iterator>
using namespace std;

// class constructor - queue size set to zero
template <class DataType>
miniQueueLT<DataType>::miniQueueLT() {
    elementCount = 0;
    content.resize(0);
}

// class destructor - return memory used by queue elements
template <class DataType>
miniQueueLT<DataType>::~miniQueueLT() {
    content.clear();
}

// add an item to back of queue
template <class DataType>
void miniQueueLT<DataType>::enqueue(const DataType &value) {
    content.push_back(value);
    ++elementCount;
}

// remove front item of queue & return its value, issue exception if empty
template <class DataType>
void miniQueueLT<DataType>::dequeue() {
    if (IsEmpty())
        throw underflow_error("queue empty");

    content.pop_front();
    --elementCount;
}

// return front item of queue, issue exception if empty
template <class DataType>
DataType& miniQueueLT<DataType>::front() {
    if(IsEmpty())
        throw underflow_error("queue empty");

    return content.front();
}

// return constant front item of queue, issue exception if empty
template <class DataType>
const DataType& miniQueueLT<DataType>::front() const {
    if (IsEmpty())
        throw underflow_error("queue empty");

    return content.front();
}

// print all queue content (front to back), issue exception if empty
template <class DataType>
void miniQueueLT<DataType>::PrintQueue() const {
    if (IsEmpty())
        cout << "queue empty";

    else {
        cout << "(front)\t";

        typename list<DataType>::const_iterator cit;
        for (cit = content.cbegin(); cit != content.cend(); cit++)
            cout << *cit << " ";

        cout << "\t(back)";
    }

    cout << endl << endl;
}

// return true if queue is empty
template <class DataType>
bool miniQueueLT<DataType>::IsEmpty() const {
    return content.empty();
}

// returns the number of elements in the queue
template <class DataType>
int miniQueueLT<DataType>::size() const {
    return content.size();
}
