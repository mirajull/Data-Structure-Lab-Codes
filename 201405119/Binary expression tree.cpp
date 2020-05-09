#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

struct node
{
    char op;
    node*left;
    node*right;
};

void Postorder(node*Root)
{
    if(Root!=NULL)
    {

        Postorder(Root->left);
        Postorder(Root->right);
        cout <<Root->op<<" ";

    }
}

int main()
{
    char s[100];
    int i,k=0;
    char c;
    scanf("%s",s);
    node*root=new node;
    root->op=s[0];
    root->left=NULL;
    root->right=NULL;

    while(scanf("%s",s)!=EOF)
    {
        //if(s=="-1")break;

        node *temp=root;

        for(i=0;i<strlen(s)-2;i++)
        {
            if(s[i]=='L')
            {
                temp=temp->left;
            }
            else if(s[i]=='R')
            {
                temp=temp->right;
            }
        }
        if(s[i]=='L'){
                temp->left=new node;
                temp=temp->left;
                temp->left=NULL;
                temp->right=NULL;
                temp->op=s[i+1];
        }
        else if(s[i]=='R')
        {
                temp->right=new node;
                temp=temp->right;
                temp->left=NULL;
                temp->right=NULL;
                temp->op=s[i+1];
        }
    }
    Postorder(root);
    return 0;
}
