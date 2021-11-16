//
// Created by Logan on 11/15/2021.
//

#include "queue.h"

Queue::Queue(){
    front = nullptr, back = nullptr;
} // End of constructor

Queue::~Queue(){
    clearQueue();
} // End of destructor

bool Queue::enqueue(int id, const string*data){
    bool didEnqueue = false;
    bool hasDupe = testDuplicate(&id);
    if(!hasDupe){
        Node *newNode = new Node();
        initializeNode(&id, data, newNode);
        if(!front){
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
        }
    }
    return didEnqueue;
} // End of enqueue

bool Queue::dequeue(){
    bool didDequeue = false;
    if(!isEmpty()){
        for(int i =0; i < back-1; i++){
            queue[i]->id = queue[i+1]->id;
            queue[i]->data = queue[i+1]->data;
        }
        queue[back-1]->id = 0;
        queue[back-1]->data = "";
        delete queue[back-1];
        back--;
        didDequeue = true;
    }
    return didDequeue;
} // End of dequeue

void Queue::printQueue(){
    if(!isEmpty()) {
        for (int i = 0; i < back; i++) {
            std::cout << "\tposition: " << i << " : id: " << queue[i]->id << " : data: " << queue[i]->data << std::endl;
        }
    } else {
        std::cout << "\tno data to print" << std::endl;
    }
} // End of printQueue

void Queue::getQueueElement(int id, Data *data){
    for(int i =0; i < back; i++){
        if(queue[i]->id == id){

        }
    }
} // End of getQueueElement

bool Queue::isEmpty() {return back==0;} // End of isEmpty

bool Queue::peek(Data *data){
    bool canPeek = false;
    if(!isEmpty()){

        canPeek = true;
    }
    return canPeek;
} // End of peek

int Queue::size(){return back;} // End of size

void Queue::clearQueue(){
    if(!isEmpty()) {
        for(int i = back-1; i >= 0; i--) {

            back--;
        }
    }
} // End of clearQueue

bool Queue::testDuplicate(int *id) {
    bool hasDupe = false;
    Node *position = front;
    while ((front != nullptr) && *id > position->data.id && position->next != nullptr) {position = position->next;}
    if(front != nullptr && *id == position->data.id) {hasDupe = true;}
    return hasDupe;
} // End of testDuplicate

// Private methods
void Queue::initializeNode(int *id, const string *data, Node *newNode){
    newNode->data.id = *id;
    newNode->data.data = *data;
    newNode->next = nullptr;
} // End of initializeNode