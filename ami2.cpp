#include<iostream>
#include<cstdio>

using namespace std;

class tree
{
public:
    int n;
	int*ara=new int[100];
	int k ;
	tree(int a)
	{
		n=a;
		k=a;
		for(int i=1;i<=n;i++)
		{
		    ara[i]=-1;
		}
	}
	int Find(int a)
	{
		if(ara[a]==-1) return a;
		else
		{
			ara[a]=Find(ara[a]);
			return ara[a];
		}
	}
	void Union(int a,int b)
	{
		int p,q;
		p=Find(a);
		q=Find(b);
		if(p==q)   cout<<k<<" CYCLE FORMED!"<<endl;
		else
		{
			ara[q]=p;
			cout<<--k<<endl;
		}
	}
};
int main()
{
	int n,a,b;
	cin>>n;
	tree obj(n);
	while( cin>>a && cin>>b )
     {
          obj.Union(a,b);
     }
	return 0;
}



