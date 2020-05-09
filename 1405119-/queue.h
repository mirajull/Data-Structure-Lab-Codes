#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "Data.h"

class Queue
{
public:
    Queue()                 // constructor
    void enqueue(Data x);   // enqueues x
    void dequeue();         // removes the front element  
    Data front();           // returns the element from the front (without removing it)
    int size();             // returns the count of elements in the queue
    bool isEmpty();         // returns true of the queue is empty
    void print();           // print the elements of the queue in console        
};

#endif