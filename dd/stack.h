#ifndef DS_STACK_H
#define DS_STACK_H

#include "Data.h"

struct link()
{
    data x;
    link*next;
};
class Stack
{
public:
    struct link*head;
    Stack();            // constructor
    void push(Data x);  // pushes x into stack
    void pop();         // removes the top element of stack
    Data top();         // returns the top element of stack (without removing it)
    int size();         // returns the count of elements in the stack
    bool isEmpty();     // returns true if the stack is empty
    void print();       // prints the elements of the stack in console
};
stack::stack()
{

}
void::stack push()
{

}
void::stack pop()
{

}
Data::stack top()
{

}
bool::stack isEmpty()
{

}
void::stack print()
{

}

#endif
