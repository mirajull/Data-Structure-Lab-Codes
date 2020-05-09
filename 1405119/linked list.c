#include<stdio.h>

struct node
{
    int id;
    int frequency;
    node*next;
};
node*root=NULL;


void insert(int id)
{
    if(root==NULL)
	{
		root=new node();
		root->id=id;
		root->frequency=
        root->next=NULL;
	}
	else
	{
		node*current_node=root;
		while(current_node->next!=NULL)
		{
			current_node=current_node->next;
		}
		node*newnode = new node();
		newnode->roll=roll;
		newnode->next=NULL;

		current_node->next=newnode;
	}
}
void delet(int id)
{



}
void find(int id)
{



}
void reverse()
{


}
void print()
{
    node*current_node=root;
    while(current_node!=NULL)
    {
        printf("%d\n",current_node->roll);
        current_node=current_node->next;
    }
}

int main()
{
    struct node student;
    return 0;

}
