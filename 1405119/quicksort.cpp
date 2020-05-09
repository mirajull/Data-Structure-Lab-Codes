#include<iostream>
using namespace std;

int MedianOfThreePartition(int a[],int p, int r) {
    int x=a[p];
    int y=a[(r-p)/2+p];
    int z=a[r-1];
    int i=p-1;
    int j=r;
    if (y>x && y<z||y>z&&y<x ) x=y;
    else if (z>x&&z<y||z>y&&z<x ) x=z;
    j--;i++;
    while (1) {
        while (a[j] > x){j--;}
        while (a[i] < x){i++;}
        if(i<j)
        {
            swap(a[i],a[j]);
        }
        else
        {
            return j+1;
        }
    }
}
void QuickSortMedian(int a[],int start,int end) {
    int q;
    if (end-start<2) return;
    q=MedianOfThreePartition(a,start,end);
    QuickSortMedian(a,start,q);
    QuickSortMedian(a,q,end);
}


int main()
{
    int n,ara[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    QuickSortMedian(ara,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<ara[i]<<" ";
    }
    return 0;
}
