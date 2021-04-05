/*
    DNode.h
    COSC 220-750 Project 2
    definition of class DNode
    a doubly linked list

    Lauren Taylor
    Created: 25 March 2021
    Current: 5 April 2021
*/

#ifndef DNODE_H
#define DNODE_H

template <typename T>
class DNode {
    public:
        T nodeValue;
        DNode* next; 
        DNode* prev;

        // constructors
        DNode()
            {next = NULL; prev = NULL;}
        DNode(const T &value, DNode* p = NULL, DNode* n = NULL)
            {nodeValue = value; prev = p; next = n;}
};

#endif /* DNode.h */