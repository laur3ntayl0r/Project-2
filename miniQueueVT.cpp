/*
    miniStackVT.cpp
    COSC 220-750 Project 2
    implementation file for miniQueueVT.h
    a miniQueue implemented using STL <vector>

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#include "miniQueueVT.h"
#include <iostream>
using namespace std;

template <class DataType>
miniQueueVT<DataType>::miniQueueVT() {
    elementCount = 0;
    content.resize(0);
}

template <class DataType>
miniQueueVT<DataType>::~miniQueueVT() {
    content.clear();
}

template <class DataType>
void miniQueueVT<DataType>::enqueue(const DataType &value) {
    content.push_back(value);
    ++elementCount;
}

template <class DataType>
void miniQueueVT<DataType>::dequeue() {
    if (content.empty())
        throw underflow_error("queue empty");

    content.erase(content.begin());

    --elementCount;
}

template <class DataType>
DataType& miniQueueVT<DataType>::front() {
    if (content.empty())
        throw underflow_error("queue empty");

    return content.front();
}

template <class DataType>
const DataType& miniQueueVT<DataType>::front() const {
    if (content.empty())
        throw underflow_error("queue empty");

    return content.front();
}

template <class DataType>
void miniQueueVT<DataType>::PrintQueue() const {
    if (content.empty())
        cout << "queue empty";

    else {
        cout << "(front) ";

        for (int i = 0; i < content.size(); i++)
            cout << content[i] << " ";
    }

    cout << endl << endl;
}

template <class DataType>
bool miniQueueVT<DataType>::IsEmpty() const {
    return content.empty();
}

template <class DataType>
int miniQueueVT<DataType>::size() const {
    return content.size();
}

