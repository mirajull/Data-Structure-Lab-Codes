#include<bits/stdc++.h>
using namespace std;
#define max 10000
vector<int>edge[max];

int main()
{
    int x,y,a,b;
    cin>>x>>y;
    for(int i=0;i<y;i++)
    {
        cin>>a>>b;
        edge[b].push_back(a);
    }
    for(int i=1;i<=a;i++)
    {
        cout<<"indegree : "<<edge[i].size()<<endl;
    }
    return 0;
}
