#include<iostream>
using namespace std;
#include "stack2.h"

int main()
{
    int x,i;
    stack S;
    cin>>x;
    int A[100],lnA[100];
    for(i=1;i<=x;i++)
    {
        cin>>A[i];
    }
    for(i=1;i<=x;i++)
    {
        Data y;
        while(!S.isEmpty() && A[S.top().x]>= A[i])
        {
            S.pop();
        }
        if(S.isEmpty())
        {
            lnA[i]=i;
        }
        else
        {
            lnA[i]=i-S.top().x;
        }
        y.x=i;
        S.push(y);
    }
    for(i=1;i<=x;i++)
    {
        cout<<lnA[i]<<" ";
    }
    return 0;
}




