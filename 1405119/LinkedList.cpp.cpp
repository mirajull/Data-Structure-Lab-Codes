#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int id;
    int frequency;
    node*next;
};
node*root=NULL;

void print(node*root)
{
    node*current_node=root;
    while(current_node!=NULL)
    {
        printf("<%d ,%d> ",current_node->id,current_node->frequency);
        current_node=current_node->next;
    }
}
void Insert(int x,node*root)
{
    node*head=root;
    node*curent_node=root;
    int f=0;
    while(curent_node!=NULL)
    {
        if(curent_node->id=x)
        {
            curent_node->frequency++;
            f++;
        }
        else{
        curent_node=curent_node->next;
        }
    }
    if(f==0)
    {
        if(root==NULL)
        {
		root=new node;
		root->id=x;
		root->frequency=1;
        root->next=NULL;
        }
        else
        {
            node*current_node=root;
            while(current_node->next!=NULL)
            {
			current_node=current_node->next;
            }
            node*newnode =new node;
            newnode->id=x;
            newnode->next=NULL;
            current_node->next=newnode;
        }
    }
    print(root);
}
void Delete(int x,node*root)
{
    int f=0;
    node *current_node=root;
	node *previous_node=NULL;
	while(current_node!=NULL)
    {
        if(current_node->id==x)
        {
            current_node->frequency--;
            if(current_node->frequency==0)
            {
                delete(current_node);
            }
            f++;
            break;
        }
        current_node=current_node->next;
    }
    if(f==0)
    {
        cout<<"Not Found"<<endl;
    }

}
void Find(int x,node*root)
{
    int f=0;
    node*current_node=root;
    while(current_node!=NULL)
    {
        if(current_node->id==x)
        {
            printf("frequency of data with id =%d is %d",current_node->id,current_node->frequency);
            f++;
        }
    }
    if(f==0)
    {
        printf("frequency of data with id =%d is %d",x,0);
    }
}
void Reverse(node*root)
{
    node*current,*prev,*next;
    current=root;
    prev=NULL;
    while(current!=NULL)
    {
        current=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    root=prev;
    print(root);
}

int main()
{
    int x;
  //  node*root=NULL;
    while(1)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='T')break;
        if(ch!='R')
        {
            scanf(" %d",&x);
            getchar();
            if(ch=='I')
            {
                Insert(x,root);
            }
            else if(ch=='F')
            {
                Find(x,root);
            }
            else if(ch=='D')
            {
                Delete(x,root);
            }
        }
        else{
            if(ch=='R')
            {
                Reverse(root);
            }
        }
        printf("\n");
    }
    return 0;

}
