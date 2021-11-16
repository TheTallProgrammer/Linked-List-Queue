//
// Created by Logan on 11/15/2021.
//

#ifndef QUEUE_DATA_H
#define QUEUE_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
};

#endif //QUEUE_DATA_H