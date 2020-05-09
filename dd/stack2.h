#ifndef DS_STACK_H
#define DS_STACK_H

#include "Data.h"

/* struct Data
{
    int x;
}; */

int tos=0;

struct node
{
    Data x;
    struct node *next;
};
class stack
{
    struct node *ttop;
public:
    stack();
    void push(Data x);
    void pop();
    Data top();
    int size();
    bool isEmpty();
    void print();
};

stack::stack()
{
    ttop=NULL;
}

void stack::push(Data x)
{
    cin>>x.x;
    //cout<<endl;
    int value=x.x;
    struct node *ptr;
    ptr=new node;
    ptr->x.x=value;
    ptr->next=NULL;
    if(ttop!=NULL)
        ptr->next=ttop;
    ttop=ptr;
    tos++;

}
void stack::pop()
{
    struct node *temp;
    if(ttop==NULL)
    {
        cout<<endl<<"The stack is empty."<<endl;
    }
    temp=ttop;
    ttop=ttop->next;
    delete temp;
    tos--;
}

Data stack::top()
{
    if(ttop==NULL)
    {
        cout<<endl<<"The stack is empty."<<endl;
    }
    return (ttop->x);
}

int stack::size()
{
    return tos;
}

bool stack::isEmpty()
{
    if(tos>0)
    {
        return false;
    }
    return true;
}

void stack::print()
{
    struct node *now=ttop;
    while(now!=NULL)
    {
        cout<<now->x.x<<"  ";
        now=now->next;
    }
}

#endif // DS_STACK_H

/*
int main()
{
    stack s;
    Data x;
    char choice;
    while(1)
    {
        cin>>choice;
        switch(choice)
        {
            case 'p':
                s.push(x);
                break;
            case 'q':
                s.pop();
                break;
            case 's':
                s.print();
                break;
            case 't':
                return 0;
                break;
        }

    }
    return 0;
}*/
