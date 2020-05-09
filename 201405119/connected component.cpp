#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int arra[100000];
int Find(int a)
{
    if(arra[a]==a) return a ;
    else arra[a]=Find(arra[a]);
    return arra[a];


}
    bool differ(int a,int b)
    {
        int root1=Find(a);
        int root2=Find(b);
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
    for(int i=1;i<=n;i++)
    {
        (arra[i])=i;
    }
    //n--;
    //cout<<n<<endl;
    bool x;
    while(cin>>a)
    {
        cin>>b;

        if(differ(a,b)==true)
        {
            Union(a,b);
            cout<<--n<<endl;
        }
        else
        {

            cout<<n<<" CYCLE FORMED!"<<endl;
        }

    }
    return 0;
}
