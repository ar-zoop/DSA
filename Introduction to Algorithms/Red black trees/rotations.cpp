#include <bits/stdc++.h>
using  namespace std;

typedef struct tree_node
{
    struct tree_node *parent;
    struct tree_node *left;
    int data;
    struct tree_node *right;
} node;

node *root, *temp, *x;

void create_node()
{
    temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
}

void insert_node(int data)
{
    create_node();
    temp->data = data;
    if (root == NULL)
    {
        root = temp;
        return;
    }
    else
    {
        x = root;
        while (x != NULL)
        {
            if (x->data < temp->data)
            {
                if (x->right == NULL)
                {
                    x->right = temp;
                    temp->parent = x;
                    x = NULL;
                }
                else
                {
                    x = x->right;
                }
            }
            else
            {
                if (x->left == NULL)
                {
                    x->left = temp;
                    temp->parent = x;
                    x = NULL;
                }
                else
                {
                    x = x->left;
                }
            }
        }
    }
}

void inorder(node *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}

node *search(node *n, int data)
{
    while (n != NULL && n->data != data)
    {
        if (n->data < data)
        {
            n = n->right;
        }
        else
        {
            n = n->left;
        }
    }
    if (n != NULL && n->data == data )
    {
        return n;
    }

    return NULL;
}

void right_rotation(node *p){
    node* q=p->left;
    node* hold=q->right;
    q->right=p;
    p->left=hold;
    if (p == root)
    {
        root = q;
    }

    return;

    
}

void left_rotation(node *p){
    node *q=p->right;
    node *hold=q->left;
    q->left=p;
    p->right=hold;
    if (p == root)
    {
        root = q;
    }
    return;
}



int main()
{
    insert_node(50);
    insert_node(45);
    insert_node(60);
    insert_node(55);
    insert_node(70);
    insert_node(65);
    insert_node(80);

    inorder(root);cout<<endl;

    // cout << (search(root, 10))->data<<endl;
    node *n = search(root, 50);
    right_rotation(n);
    inorder(root);cout<<endl;

    return 0;
}