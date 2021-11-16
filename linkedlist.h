//
// Created by Logan on 11/15/2021.
//

#ifndef SIMPLE_LINKED_LIST_LINKEDLIST_H
#define SIMPLE_LINKED_LIST_LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList{

public:

    // Constructor/Destructor
    LinkedList();
    ~LinkedList();

    //Methods
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    bool getTail(Data *);

private:

    // Pointer to the first node
    Node *head, *tail;

    // Private methods
    void initializeNode(int *, string*, Node*);
    bool checkOperation(Node *, Node *, int *);
    void insertHead(Node *);
    void insertMiddle(Node *, Node *);
    void insertTail(Node *, Node *);

}; // End of class LinkedList

#endif //SIMPLE_LINKED_LIST_LINKEDLIST_H