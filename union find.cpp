#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

//class tree
//{
//public:
//    int array[100];
//    int Find(int curr)
//    {
//        if(array[curr]==NULL)
//        {
//            return curr;
//        }
//        while(array[curr]!=NULL)
//        {
//            curr=array[curr];
//        }
//        return curr;
//    }
//    bool differ(int a,int b)
//    {
//        int root1=Find(array[a]);
//        int root2=Find(array[b]);
//        return root1!=root2;
//    }
//    void Union(int a,int b) {
//        int root1 = Find(a); // Find a’s root
//        int root2 = Find(b); // Find b’s root
//        if (root1 != root2) array[root2] = root1;
//    }
//};
int arra[100];
int Find(int curr)
{
    if(!arra[curr])
        {
            return curr;
        }
        while(arra[curr])
        {
            curr=arra[curr];
        }
        return curr;
    }
    bool differ(int a,int b)
    {
        int root1=Find(arra[a]);
        int root2=Find(arra[b]);
        return root1!=root2;
    }
    void Union(int a,int b) {
        int root1 = Find(a); // Find a’s root
        int root2 = Find(b); // Find b’s root
        if (root1 != root2) arra[root2] = root1;
    }
int main()
{
    int n,a,b;
    cin>>n;
    //int arra[n];
    for(int i=0;i<n;i++)
    {
        (arra[i])=i+1;
    }
    n--;
    cout<<n<<endl;
    bool x;
    while(1)
    {
        cin>>a>>b;
        if(a==0 &&b ==0)
        {
            break;
        }
        if(differ(a,b)==true)
        {
            Union(a,b);
            cout<<n<<endl;
        }
        else
        {
            n--;
            cout<<n<<endl;
        }

    }
    return 0;
}
