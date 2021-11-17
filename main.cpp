#include "main.h"

int main() {
    // ===== CREATING TEST DATA =====
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
//    ids[testdatasize-2] = ids[testdatasize-3];
//    strs[testdatasize-2] = "known duplicate";
//    ids[testdatasize-1] = - 1;
//    strs[testdatasize-1] = "known bad";

    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

// ===== BEGINNING THE TESTING =====

    bool didInsert = false;
    bool didRemove = false;
    int rNumCase = 0;
    int rNumIndex = 0;
    int id = 0;
    int iterationCount = 1;

    // create your queue object here
    Queue queue;

    std::cout << "\nCurrent amount of entries: " << queue.size() << std::endl;
    std::cout << "Can peek first element? ";

    bool canPeek;
    Data data;
    canPeek = queue.peek(&data);
    if(canPeek){
        std::cout << "yes. id: " << data.id << " : data: " << data.data << std::endl;
    } else {
        std::cout << "no." << std::endl;
    }

    queue.peek(&data);
    didRemove = queue.dequeue();
    std::cout << "Dequeue of front element with id " << data.id << " successful? ";
    if(didRemove){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "printing queue: " << std::endl;
    queue.printQueue();

    // try and put ALL the test data into the table and show what happens
    // Testing insert/remove methods
    std::cout << "\n**TESTING ENQUEUE/DEQUEUE**" << std::endl;
    for(int i =0; i < testdatasize; i++){
        didInsert = queue.enqueue(ids[i], &strs[i]);
        std::cout << "Enqueue of front element with id " << ids[i] << " successful? ";
        if(didInsert){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    std::cout << "\nCurrent amount of entries: " << queue.size() << std::endl;
    std::cout << "printing queue: " << std::endl;
    queue.printQueue();
    std::cout << std::endl;

    queue.getQueueElement(ids[1], &data);
    std::cout << "got queue of id: " << data.id << " : data: " << data.data << std::endl;

    std::cout << "Can peek first element? ";
    canPeek = queue.peek(&data);
    if(canPeek){
        std::cout << "yes. id: " << data.id << " : data: " << data.data << std::endl;
    } else {
        std::cout << "no." << std::endl;
    }
    std::cout << std::endl;

    // Removing the nodes (dequeue)
    for(int i =0; i < testdatasize; i++){
        queue.peek(&data);
        didRemove = queue.dequeue();
        std::cout << "Dequeue of front element with id " << data.id << " successful? ";
        if(didRemove){
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    std::cout << "\nCurrent amount of entries: " << queue.size() << std::endl;
    std::cout << "printing queue: " << std::endl;
    queue.printQueue();

    // Main testing for loop
    std::cout << "\n**TESTING ALL METHODS**" << std::endl;
    std::cout << std::endl;
    std::cout << "\n=============================" << std::endl;
    for(int i =0; i < 1000; i++){
        // Picks random index
        rNumIndex = (rand() % testdatasize);
        rNumCase = (rand()%3)+1;
        Data data;
        bool canPeek = false;
        bool didDequeue = false;
        bool hasNode = false;
        std::cout<<"Iteration: " << iterationCount << std::endl;

        switch(rNumCase){
            case 1:
                std::cout << "Enqueue of front element with id " << ids[rNumIndex] << " successful? ";
                didInsert = queue.enqueue(ids[rNumIndex], &strs[rNumIndex]);
                if(didInsert){
                    std::cout << "yes" << std::endl;
                } else {
                    std::cout << "no" << std::endl;
                }
                std::cout << "\nCurrent amount of entries: " << queue.size() << std::endl;
                std::cout << "printing queue: " << std::endl;
                queue.printQueue();
                std::cout << "\n=============================" << std::endl;
                break;

            case 2:
                std::cout << "\nCan peek first element? ";
                canPeek = queue.peek(&data);
                if(canPeek){
                    std::cout << "yes. id: " << data.id << " : data: " << data.data << std::endl;
                    std::cout << "\nDequeue of front element with id " << data.id << " successful? ";
                    didDequeue = queue.dequeue();
                    if(didDequeue){
                        std::cout << "yes" << std::endl;
                    } else {
                        std::cout << "no" << std::endl;
                    }
                } else {
                    std::cout << "no." << std::endl;
                }
                std::cout << "\nCurrent amount of entries: " << queue.size() << std::endl;
                std::cout << "\nprinting queue: " << std::endl;
                queue.printQueue();
                std::cout << "\n=============================" << std::endl;
                break;

            case 3:
                hasNode = queue.getQueueElement(ids[rNumIndex], &data);
                if(queue.size() > 0){
                    if(hasNode){
                        std::cout << "found queue element of id: " << data.id << " : data: " << data.data << std::endl;
                    } else {
                        std::cout << "Didn't find a node that matched the random search id" << std::endl;
                    }
                } else {
                    std::cout << "Queue is empty, no id to find" << std::endl;
                }
                std::cout << "\n=============================" << std::endl;
                break;
        }
        iterationCount++;
    }

    std::cout << "\n====== CLEARING QUEUE ======" << std::endl;
    queue.clearQueue();
    std::cout << "\nQUEUE CLEARED" << std::endl;
    std::cout << "\nprinting queue: " << std::endl;
    queue.printQueue();

    std::cout << "\n***************\nTESTS CONCLUDED\n***************" << std::endl;

    return 0;
}