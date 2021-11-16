#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    std::cout << "\n======================\n" << std::endl;

    // ------------------- INITIAL TESTS ------------------- //
    Queue queue;
    bool tempBool;
    Data data1;
    Data data2;
    Data data3;
    Data data4;

    // == INITIAL TESTS ==

    std::cout << "is queue empty? ";
    tempBool = queue.isEmpty();
    if(tempBool == true){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();
    std::cout << "\ncurrent size: " << queue.size() << std::endl;

    std::cout << "" << std::endl;

    // == ADDING ELEMENT ==

    for(int i =0; i < number_test_cases; i++){
        std::cout << "inserting element: " << ids[i];
        const std::string tempString = data[i];
        tempBool = queue.enqueue(ids[i], &tempString);
        std::cout << " : Success? ";
        if(tempBool == false){
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }
    }

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();
    std::cout << "\ncurrent size: " << queue.size() << std::endl;;

    // == PEEKING ==

    std::cout << "\ncan peek?";
    tempBool = queue.peek(&data1);
    if(tempBool == true){
        std::cout << " yes" << std::endl;
        std::cout << "Peeked id: " << data1.id << " : data: " << data1.data << std::endl;
    } else {
        std::cout << " no" << std::endl;
    }

    // == RETRIEVING ==

    std::cout << "\nRetrieving queue with id: " << ids[1] << std::endl;
    queue.getQueueElement(ids[1], &data2);
    std::cout << "Retrieved id: " << data2.id << " : data: " << data2.data << std::endl;

    // == REMOVING ELEMENT ==

    std::cout << "\nAttempting to dequeue front element : Success? ";
    tempBool = queue.dequeue();
    if(tempBool == true){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    std::cout << "\ncurrent size: " << queue.size() << std::endl;

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();

    // == ADDING ELEMENT ==

    std::cout << "inserting element: " << ids[1];
    const std::string tempString = data[1];
    tempBool = queue.enqueue(ids[1], &tempString);
    std::cout << " : Success? ";
    if(tempBool == false){
        std::cout << "no" << std::endl;
    } else {
        std::cout << "yes" << std::endl;
    }


    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();

    // == CLEARING ==

    std::cout << "\nclearing" << std::endl;
    queue.clearQueue();

    std::cout << "\ncurrent size: " << queue.size() << std::endl;

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();

    // == ADDING ELEMENT ==

    std::cout << std::endl;
    for(int i =0; i < number_test_cases; i++){
        std::cout << "inserting element: " << ids[i];
        const std::string tempString = data[i];
        tempBool = queue.enqueue(ids[i], &tempString);
        std::cout << " : Success? ";
        if(tempBool == false){
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }
    }

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();
    std::cout << "\ncurrent size: " << queue.size() << std::endl;

    // == CLEARING ==

    std::cout << "\nclearing" << std::endl;
    queue.clearQueue();

    std::cout << "\ncurrent size: " << queue.size() << std::endl;

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();

    int dupeIds[2] = {1,1};
    std::string string = data[0];
    std::cout << "\ninserting element: " << dupeIds[0];
    tempBool = queue.enqueue(dupeIds[0], &string);
    std::cout << " : Success? ";
    if(tempBool == false){
        std::cout << "no" << std::endl;
    } else {
        std::cout << "yes" << std::endl;
    }


    std::string newstring = data[1];
    std::cout << "inserting element: " << dupeIds[1];
    tempBool = queue.enqueue(dupeIds[1], &newstring);
    std::cout << " : Success? ";
    if(tempBool == false){
        std::cout << "no" << std::endl;
    } else {
        std::cout << "yes" << std::endl;
    }

    std::cout << "\nPrinting:" << std::endl;
    queue.printQueue();

    return 0;
}