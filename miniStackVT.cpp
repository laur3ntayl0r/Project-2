/*
    miniStackVT.cpp
    COSC 220-750 Project 2
    implementation file for miniStackVT.h
    contains functions to manipulate a miniStack implemented using STL <vector>

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#include "miniStackVT.h"
#include <iostream>
using namespace std;

// default constructor creates a stack with size zero
template <class DataType>
miniStackVT<DataType>::miniStackVT() {
    elementCount = 0;
    content.resize(0);
}

// destructor clears vector
template <class DataType>
miniStackVT<DataType>::~miniStackVT() {
    content.clear();
}

// returns the number of elements in the stack
template <class DataType>
int miniStackVT<DataType>::size() const {
    return content.size();
}

// check 
template <class DataType>
bool miniStackVT<DataType>::IsEmpty() const {
    return content.size() == 0 ? true : false;
}

template <class DataType>
void miniStackVT<DataType>::Push(const DataType &value) {
    content.push_back(value);
}

template <class DataType>
void miniStackVT<DataType>::PrintStack() const {
    if (IsEmpty())
        cout << "stack empty";

    else {
        cout << "(top) ";

        for (int i = content.size() - 1; i >= 0; i--)
            cout << content[i] << " ";
    }

    cout << endl << endl;
}

template <class DataType>
void miniStackVT<DataType>::Pop() {
    if (IsEmpty())
        throw underflow_error("stack empty");

    content.pop_back();
}

template <class DataType>
DataType& miniStackVT<DataType>::TopStack() {
    if (IsEmpty())
        throw underflow_error("stack empty");

    return content.back();
}

template <class DataType>
const DataType& miniStackVT<DataType>::TopStack() const {
    if (IsEmpty())
        throw underflow_error("stack empty");

    return content.back();
}


