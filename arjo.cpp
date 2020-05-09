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
//class btree
//{
//    public:
//        btree();
//        ~btree();
//
//        void insert(int key);
//        node *search(int key);
//        void destroy_tree();
//
//    private:
//        void destroy_tree(node *leaf);
//        void insert(int key, node *leaf);
//        node *search(int key, node *leaf);
//
//        //node *root;
//}
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
    string s;
    int i,k=0;
    char c;
    cin>>s;
    node*root=new node;
    root->op=s[0];
    root->left=NULL;
    root->right=NULL;

    while(cin>>s)
    {
        if(s=="-1")break;

        node *temp=root;

        for(i=0;i<s.size()-2;i++)
        {
            if(s[i]=='L')
            {
//                head->left=new node;
//                head=head->left;
//                head->op=s[i];
//                head->left=NULL;
//                head->right=NULL;
                temp=temp->left;
            }
            else if(s[i]=='R')
            {
                //head->right=new node;
                temp=temp->right;
            }
//            else{
//                if(k==0)
//                {
//                    //node*head=root;
//                    head=new node;
//                    head->op=s[i];
//                    //head->left=NULL;
//                    //head->right=NULL;
//                }
//                else{
//                    head->op=s[i];
//                    //head->left=NULL;
//                    //head->right=NULL;
//                }
//                k++;
//            }
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
