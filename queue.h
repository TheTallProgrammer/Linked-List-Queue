//
// Created by Logan on 11/15/2021.
//

#ifndef QUEUE_PROJECT_QUEUE_H
#define QUEUE_PROJECT_QUEUE_H

#include "data.h"
#include <iostream>

class Queue{

public:

    // Constructor/Destructor
    Queue();
    ~Queue();

    // Methods
    bool enqueue(int, string *);
    bool dequeue();
    void printQueue();
    void getQueueElement(int, Data *);
    bool isEmpty();
    bool peek(Data *);
    int size();
    bool clearQueue();
    bool testDuplicate(int *);
    void initializeNode(int *, string *, Node *);

private:

    Node *front, *back;
    int count;

};

#endif //QUEUE_PROJECT_QUEUE_H