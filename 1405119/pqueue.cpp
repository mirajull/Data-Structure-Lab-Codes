#include<iostream>
using namespace std;

struct Data{
    int key;
};

Data ara[100];
int heapsize=0;


void MaxHeapify(int i)
{
    int largest;
    int l=2*i;
    int r=2*i+1;
    if(l<=heapsize && ara[l].key>ara[i].key)
    {
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=heapsize&&ara[r].key>ara[largest].key)
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(ara[i],ara[largest]);
        MaxHeapify(largest);
    }
}
void BuildHeap()
{
    for(int i=heapsize/2;i>0;i--)
    {
        MaxHeapify(i);
    }
}
void ChangeKey(int i,int y)
{
    ara[i].key=y;
    if (i>1&&ara[i].key>ara[i/2].key){
        while (i>1){
            if (ara[i].key<=ara[i/2].key)
            {
                break;
            }
            else{
                swap(ara[i],ara[i/2]);
                i = i/2;
            }
        }
    }
    else{
        while(2*i<=heapsize)
        {
            if (ara[i].key<ara[2*i].key || ara[i].key<ara[2*i+1].key){
                if (ara[2*i].key>=ara[2*i+1].key){
                    swap(ara[i],ara[2*i]);
                    i = 2*i;
                }
            else if (2*i+1<=heapsize){
                swap(ara[i],ara[2*i+1]);
                i = 2*i+1;
                }
                else break;
            }
            else break;
        }
    }
}
void Insert(int x)
{
    heapsize=heapsize+1;
    ara[heapsize].key=-1000;
    ChangeKey(heapsize,x);
}
int FindMax()
{
    return ara[1].key;
}
void Delete(int i)
{
    swap(ara[i+1],ara[heapsize]);
    heapsize=heapsize-1;
    MaxHeapify(1);
}
int ExtractMax()
{
    int z=ara[0].key;
    Delete(0);
    return z;
}
void print()
{
    for(int j=1;j<=heapsize;j++)
    {
        cout<<ara[j].key<<" ";
    }
}
int main()
{

    int q,pos,key,y;
    char p;
    while(cin>>p)
    {
        if(p=='I')
        {
            cin>>q;
            Insert(q);
        }
        else if(p=='F')
        {
            cout<<FindMax()<<endl;
        }
        else if(p=='C')
        {
            cin>>pos>>key;
            ChangeKey(pos,key);
        }
        else if(p=='P')
        {
            print();
        }
        else if(p=='D')
        {
            cin>>y;
            Delete(y);
        }
        else if(p=='E')
        {
            cout<<ExtractMax()<<endl;

        }
    }
    return 0;
}
