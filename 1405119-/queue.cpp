#include<iostream>
using namespace std;

#include "stack2.h"
int toq=0;

class queue {
private :
    stack s1, s2;
public:
    queue();
    void enqueue(Data x);
    void dequeue();
    Data Front();
    int size();
    bool isEmpty();
    void print();
};

queue::queue()
{

}

void queue :: enqueue(Data x) {
   s1.push(x);
   toq++;
}


void queue :: dequeue() {
    if(s2.isEmpty()){
        while (!s1.isEmpty())
        {
        s2.push(s1.top());
        s1.pop();
        }
    }
    s2.pop();
    /*while (!s2.isEmpty()) {
        s1.push(s2.top());
        s2.pop();
    }*/
    toq--;
}

Data queue::Front()
{
    while (!s1.isEmpty()) {
        s2.push(s1.top());
        s1.pop();
    }
    Data y=s2.top();
    while (!s2.isEmpty()) {
        s1.push(s2.top());
        s2.pop();
    }
    return y;
}

int queue:: size()
{
    return toq;
}

bool queue::isEmpty()
{
    if(toq>0)
    {
        return false;
    }
    return true;
}

void queue ::print() {
   stack temp;
   while(!s2.isEmpty())
   {
       temp.push(s2.top());
       s2.pop();
   }
   while (!s1.isEmpty()) {
      s2.push(s1.top());
      s1.pop();
   }
   while(!temp.isEmpty())
   {
       s2.push(temp.top());
       temp.pop();
   }
   s2.print();


   /*while (!s1.isEmpty()) {
      s2.push(s1.top());
      s1.pop();
   }
   while (!s2.isEmpty()) {
      Data x=s2.top();
      cout<<x.x<<" ";
      s1.push(s2.top());
      s2.pop();
   }*/
}

int main()
{
    queue s;
    Data x;
    char choice;
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
            case 'e':
                s.enqueue(x);
                break;
            case 'd':
                s.dequeue();
                break;
            case 'p':
                s.print();
                break;
            case 't':
                return 0;
                break;
        }

    }
    return 0;
}
