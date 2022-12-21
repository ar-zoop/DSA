#include <bits/stdc++.h>
using namespace std;

typedef struct RB_tree_node
{
    struct RB_tree_node *left;
    struct RB_tree_node *right;
    int color; // 0= black, 1= red
    int data;
} node;

node *root, *temp, *x, *y;

// void RB_create_node()
// {
//     temp = (node *)malloc(sizeof(node));
//     temp->left = y;
//     temp->right = y;
//     temp->parent=NULL;
//     temp->color=1;
// }

void RB_create_node()
{
    temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    temp->color = 1;
}

void create_nil_node()
{
    // RB_create_node();
    temp = (node *)malloc(sizeof(node));
    temp->color = 0;
    temp->data = -1;
    y = temp;
}

void right_rotation(node *p)
{
    node *q = p->left;
    node *hold = q->right;
    q->right = p;
    if (hold == NULL)
    {
        p->left = NULL;
    }
    else
    {
        p->left = hold;
    }
    if (p == root)
    {
        root = q;
    }

    return;
}

void left_rotation(node *p)
{
    node *q = p->right;
    node *hold = q->left;
    q->left = p;
    if (hold == NULL)
    {
        p->right = NULL;
    }
    else
    {
        p->right = hold;
    }
    if (p == root)
    {
        root = q;
    }
    return;
}

node* search(node *n, int data)
{
    node *p=NULL;
    while (n != NULL && n->data != data)
    {
        if (n->data < data)
        {
            p=n;
            n = n->right;
        }
        else
        {
            p=n;
            n = n->left;
        }
    }
    if (n != NULL && n->data == data)
    {
        // cout << "found" << endl;
        return p;
    }
    // cout << "not found" << endl;
    return NULL;
}

void RB_insert_fixup(node *z)
{
    node *parent = search(root, z->data);
    cout<<"parent->data= "<<parent->data<<endl;
    while ((parent)->color == 1)
    {
        node *grandparent = search(root, parent->data);
        cout << "grandparent->data= " << grandparent->data << endl;
        if (grandparent!=NULL && grandparent->right == parent)
        {
            if ((grandparent->left)->color == 1)
            {
                (grandparent->left)->color = 0;
                parent->color = 0;
                if (grandparent != root)
                {
                    grandparent->color = 1;
                }
                z = grandparent;
            }
            else
            {
                if (z == parent->right)
                {
                    z = parent;
                    left_rotation(z);
                }
                parent->color = 0;
                if(grandparent!=root)grandparent->color = 1;
                right_rotation(grandparent);
            }
        }
        else if(grandparent!=NULL)
        {
            if ((grandparent->right)->color == 1)
            {
                (grandparent->right)->color = 0;
                (parent)->color = 0;
                if (grandparent != root)
                {
                    grandparent->color = 1;
                }
                z = grandparent;
            }
            else
            {
                if (z == parent->left)
                {
                    z = parent;
                    right_rotation(z);
                }
                parent->color = 0;
                if (grandparent != root)
                    grandparent->color = 1;
                left_rotation(grandparent);
            }
        }
    }
}

void RB_insert_node(int data)
{
    RB_create_node();
    temp->data = data;
    if (root == NULL)
    {
        root = temp;
        root->color = 0;
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
                    x = NULL;
                }
                else
                {
                    x = x->left;
                }
            }
        }
    }
    RB_insert_fixup(temp);
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

int main()
{
    // create_nil_node();
    RB_insert_node(41);
    inorder(root);
    cout << endl;
    // cout<<y->data<<endl;
    RB_insert_node(38);
    inorder(root);
    cout << endl;

    RB_insert_node(31);
    inorder(root);
    cout << endl;
    RB_insert_node(12);
    inorder(root);
    cout << endl;
    RB_insert_node(19);
    inorder(root);
    cout << endl;
    RB_insert_node(8);
    inorder(root);
    cout << endl;
    return 0;
}