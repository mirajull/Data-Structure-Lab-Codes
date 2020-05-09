#include <iostream>
using namespace std;

struct Data
{
    int x;
};
struct link
{
    Data x;
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

void Stack::push(Data x)
{

}
void Stack::pop()
{

}
Data Stack::top()
{

}
bool Stack::isEmpty()
{

}
void Stack:: print()
{

}
int main()
{
    return 0;
}
