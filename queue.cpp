//
// Created by Logan on 11/15/2021.
//

#include "queue.h"

Queue::Queue(){
    front = nullptr, back = nullptr;
    count = 0;
} // End of constructor

Queue::~Queue(){
    clearQueue();
} // End of destructor

bool Queue::enqueue(int id, string*data){
    bool didEnqueue = false;
    bool hasDupe = testDuplicate(&id);
    if((id > 0 && data->length() > 0) && !hasDupe){
        Node *newNode = new Node();
        initializeNode(&id, data, newNode);
        if(!front){
            front = newNode;
            back = front;
        } else {
            back->next = newNode;
            back = newNode;
            newNode->next = nullptr;
        }
        count++;
        didEnqueue = true;
    }
    return didEnqueue;
} // End of enqueue

bool Queue::dequeue(){
    bool didDequeue = false;
    if(!isEmpty() && front->next != nullptr){
        Node *temp = front;
        front = front->next;
        temp->next = nullptr;
        delete temp;
        didDequeue = true;
        count--;
    } else if(!isEmpty() && front->next == nullptr){
        Node *temp = front;
        front = nullptr;
        back = front;
        delete temp;
        didDequeue = true;
        count--;
    }
    return didDequeue;
} // End of dequeue

void Queue::printQueue(){
    if(!isEmpty()) {
        Node *position = front;
        int iteration = 0;
        while(position!= nullptr){
            std::cout << "\tposition: " << iteration << " : id: " << position->data.id << " : data: " << position->data.data << std::endl;
            position = position->next;
            iteration++;
        }
    } else {
        std::cout << "\tno data to print" << std::endl;
    }
} // End of printQueue

bool Queue::getQueueElement(int id, Data *data){
    Node *position = front;
    bool gotNode = false;
    while ((front!=nullptr) && position->next != nullptr && !gotNode) {
        if(id == position->data.id){
            data->id = position->data.id;
            data->data = position->data.data;
            std::cout << "id: " << position->data.id << std::endl;
            gotNode = true;
        } else if (id!=position->data.id){
            data->id = 0;
            data->data = "";
        }
        position = position->next;
    }
    if ((front != nullptr) && id!=position->data.id){
        data->id = 0;
        data->data = "";
    }
    return gotNode;
} // End of getQueueElement

bool Queue::isEmpty() {return front == nullptr;} // End of isEmpty

bool Queue::peek(Data *data){
    if(!isEmpty()){
        data->id = front->data.id;
        data->data = front->data.data;
    }
    return front;
} // End of peek

int Queue::size(){return count;} // End of size

bool Queue::clearQueue(){
    Node *position;
    while(front!=nullptr){
        position = front;
        front = front->next;
        delete position;
        count--;
    }
    return front;
} // End of clearQueue

bool Queue::testDuplicate(int *id) {
    bool hasDupe = false;
    Node *position = front;
    if(front != nullptr && *id == position->data.id) {hasDupe = true;} else {
        while ((front != nullptr) && !hasDupe && position->next != nullptr) {
            if (*id == position->data.id) { hasDupe = true; }
            else {
                position = position->next;
                if (*id == position->data.id) { hasDupe = true; }
            }
        }
    }
    return hasDupe;
} // End of testDuplicate

// Private methods
void Queue::initializeNode(int *id, string *data, Node *newNode){
    newNode->data.id = *id;
    newNode->data.data = *data;
    newNode->next = nullptr;
} // End of initializeNode