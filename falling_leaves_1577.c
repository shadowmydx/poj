#include <stdio.h>
#include <stdlib.h>
#define MAXN 9000000

typedef struct Node
{
    char val;
    struct Node *left;
    struct Node *right;
}Node;

char node[MAXN];
int total = 0;
Node *Root = NULL;

void preOrder(Node *root)
{
    if (root == NULL) return;
    putchar(root->val);
    preOrder(root->left);
    preOrder(root->right);
    free(root);
}

Node *insertNode(Node *root,int num)
{
    if (root == NULL)
    {
        Node *tmp = (Node *)malloc(sizeof(Node));
        tmp->val = num;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    if (root->val > num)
        root->left = insertNode(root->left,num);
    else root->right = insertNode(root->right,num);
    return root;
}

void buildTree()
{
    int i,ptr = 1;
    for (i = total - 1;i >= 0;i --) //total - 1 point to the root.
    {
        Root = insertNode(Root,node[i]);
    }
}

void init()
{
    int i;
    total = 0;
    Root = NULL;
}

int main(void)
{
    int c;
    while ((c = getchar()) != '$')
    {
        switch (c)
        {
            case '*'  : buildTree();
                        preOrder(Root);
                        printf("\n");
                        init();
                        break;
            case '\n' : //setAddr();
                        break;
            default   : node[total++] = c;
                        break;
        }
    }
    buildTree();
    preOrder(Root);
    return 0;
}
