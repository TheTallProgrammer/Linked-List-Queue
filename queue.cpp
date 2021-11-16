//
// Created by Logan on 11/15/2021.
//

#include "queue.h"

Queue::Queue(){
    front = 0;
    back = 0;
} // End of constructor

Queue::~Queue(){
    clearQueue();
} // End of destructor

bool Queue::enqueue(int id, const string*data){
    bool didEnqueue = false;
    if(back < QUEUESIZE){
        if(id >= 0 && data->length() > 0){
            bool hasDupe = testDuplicate(&id);
            if(!hasDupe){
                // Allocating new memory for new Data struct that will be added to the queue
                Data *newData = new Data;
                newData->id = id;
                // Have to dereference the data string in order to get its contents
                newData->data = *data;
                // Executes code and enqueues the data into the queue, then increments the back int
                queue[back++] = newData;
                didEnqueue = true;
            }
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
            data->id = queue[i]->id;
            data->data = queue[i]->data;
        }
    }
} // End of getQueueElement

bool Queue::isEmpty() {return back==0;} // End of isEmpty

bool Queue::peek(Data *data){
    bool canPeek = false;
    if(!isEmpty()){
        data->id = queue[front]->id;
        data->data = queue[front]->data;
        canPeek = true;
    }
    return canPeek;
} // End of peek

int Queue::size(){return back;} // End of size

void Queue::clearQueue(){
    if(!isEmpty()) {
        for(int i = back-1; i >= 0; i--) {
            delete queue[i];
            back--;
        }
    }
} // End of clearQueue

bool Queue::testDuplicate(int *id) {
    bool hasDupe = false;
    for(int i = 0; i < back; i++){
        if(queue[i]->id == *id){
            hasDupe = true;
        }
    }
    return hasDupe;
} // End of testDuplicate