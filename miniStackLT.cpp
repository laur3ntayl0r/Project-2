/*
    miniStackLT.cpp
    COSC 220-750 Project 2
    implementation file for miniStackLT.h
    a miniStack implemented using STL <list>

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#include "miniStackLT.h"
#include <iostream>
#include <iterator>
using namespace std;

template <class DataType>
miniStackLT<DataType>::miniStackLT() {
    elementCount = 0;
    content.resize(0);
}

template <class DataType>
miniStackLT<DataType>::~miniStackLT() {
    content.clear();
}

template <class DataType>
int miniStackLT<DataType>::size() const {
    return content.size();
}

template <class DataType>
bool miniStackLT<DataType>::IsEmpty() const {
    return content.empty();
}

template <class DataType>
void miniStackLT<DataType>::Push(const DataType &value) {
    content.push_back(value);
}

template <class DataType>
void miniStackLT<DataType>::PrintStack() const {
    if (IsEmpty())
        cout << "stack empty";

    else {
        cout << "(top)\t";

        typename list<DataType>::const_reverse_iterator rit;
        for (rit = content.rbegin(); rit != content.rend(); rit++)
            cout << *rit << " ";

        cout << "\t(bottom)";
    }

    cout << endl << endl;
}

template <class DataType>
void miniStackLT<DataType>::Pop() {
    if (IsEmpty())
        throw underflow_error("stack empty");

    else
        content.pop_back();
}

template <class DataType>
DataType& miniStackLT<DataType>::TopStack() {
    if (IsEmpty())
        throw underflow_error("stack empty");

    else
        return content.back();
}

template <class DataType>
const DataType& miniStackLT<DataType>::TopStack() const {
    if (IsEmpty())
        throw underflow_error("stack empty");

    else
        return content.back();
}