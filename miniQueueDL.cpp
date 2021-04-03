/*
    miniQueueDL.cpp
    COSC 220-750 Project 2
    implementation file for miniQueueDL.h
    a miniQueue implemented using doubly linked list

    Lauren Taylor
    Created: 25 March 2021
    Current: 3 April 2021
*/

#include "miniQueueDL.h"
#include <iostream>
using namespace std;

// class constructor - queue size set to zero
template <class T>
miniQueueDL<T>::miniQueueDL() {
    elementCount = 0;
    head = NULL;
    tail = NULL;
}

// class destructor - return memory used by queue elements
template <class T>
miniQueueDL<T>::~miniQueueDL() {
    DNode<T> *curr = head;

    while (curr != NULL) {
        delete curr;
        curr = curr->next;
    }
}

// add an item to back of queue
template <class T>
void miniQueueDL<T>::enqueue(const T &value) {
    // if stack is empty create head node with nodeValue = value
    if (IsEmpty()) {
        head = new DNode<T>(value);

        // since there's only 1 node, both head & tail will point to it
        tail = head;
    
    } else {
        // create new node with nodeValue = value and prev = tail
        DNode<T> *newNode = new DNode<T>(value, tail);

        // last node now points to a new last node
        tail->next = newNode;

        // tail now points to the new last node
        tail = tail->next;
    }

    // increment number of elements by 1
    ++elementCount;
}

// remove first item from queue, issue exception if empty
template <class T>
void miniQueueDL<T>::dequeue() {
    // throwing exception if queue is empty
    if (IsEmpty())
        throw underflow_error("queue empty");

    // keeping track of the node that will be the new head node
    DNode<T> *temp = head->next;

    delete head;

    // new head node is the node that was after the old head node
    head = temp;

    // head node's prev member should point to NULL
    head->prev = NULL;

    // decrease element count by 1
    --elementCount;
}

// return the value of the front item in the queue, issue
// exception if queue is empty
template <class T>
T& miniQueueDL<T>::front() {
    // throwing exception if queue is empty
    if (IsEmpty())
        throw underflow_error("queue empty");

    return head->nodeValue;
}

// return value of front item in the queue, issue exception
// if queue is empty
template <class T>
const T& miniQueueDL<T>::front() const {
    // throwing exception if queue is empty
    if (IsEmpty())
        throw underflow_error("queue empty");

    return head->nodeValue;
}

// print all queue content (front to back), issue exception if
// queue is empty
template <class T>
void miniQueueDL<T>::PrintQueue() const {
    if (IsEmpty())
        cout << "queue empty";

    else {
        DNode<T>* curr = head;

        cout << "(front)\t";

        while (curr != NULL) {
            cout << curr->nodeValue << " ";
            curr = curr->next;
        }

        cout << "\t(back)";
    }
    
    cout << endl << endl;
}

// returns true if the queue is empty
template <class T>
bool miniQueueDL<T>::IsEmpty() const {
    return head == NULL ? true : false;
}

// returns the number of elements in the queue
template <class T>
int miniQueueDL<T>::size() const {
    return elementCount;
}