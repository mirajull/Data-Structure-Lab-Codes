#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    char key;
    struct _Node *left;
    struct _Node *right;
} Node;

typedef struct _LCAData
{
    Node *lca;
    int nFound;
} LCAData;

LCAData LCA(Node *r, char a, char b)
{
    LCAData d1 = {0}, d2 = {0}, d = {0};

    if (r->left)
    {
        d1 = LCA(r->left, a, b);
        if (d1.lca != NULL)
            return d1;
    }
    if (r->right)
    {
        d2 = LCA(r->right, a, b);
        if (d2.lca != NULL)
            return d2;
    }

    if (r->key == a || r->key == b)
        d.nFound = 1;

    d.nFound += d1.nFound + d2.nFound;
    if (d.nFound == 2)
    {
        d.lca = r;
    }

    return d;
}


void insert(Node **r, char *s)
{
    if (*s == 'L')
        insert(&((*r)->left), s+1);
    else if (*s == 'R')
        insert(&((*r)->right), s+1);
    else
    {
        *r = (Node*)malloc(sizeof(Node));
        (*r)->left = (*r)->right = NULL;
        (*r)->key = *s;
    }
}

//
// Free the entire tree rooted at node
//
void freeTree(Node *node)
{
    if (!node)
        return;

    if (node->left)
        freeTree(node->left);
    if (node->right)
        freeTree(node->right);

    free(node);
}

int main()
{
    int roll;
    double score;
    char str[30];
    Node *root = NULL;

    freopen("in.txt", "r", stdin);

    while (gets(str) && *str)
    {
        insert(&root, str);
    }

    while (NULL != gets(str))
    {
        printf("%c\n", LCA(root, str[1], str[2]).lca->key);
    }

    freeTree(root);
    root = NULL;

    return 0;
}
