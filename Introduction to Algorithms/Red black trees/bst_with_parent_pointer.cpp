#include <bits/stdc++.h>
using namespace std;

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
node *search(node *n, int data)
{
    node *p;
    while (n != NULL && n->data != data)
    {
        if (n->data < data)
        {
            p = n;
            n = n->right;
        }
        else
        {
            p = n;
            n = n->left;
        }
    }
    if (n != NULL && n->data == data && n != root)
    {
        return p;
    }
    if (n != NULL && n->data == data && n == root)
    {
        return n;
    }

    return NULL;
}

node *findSuccessor(node *n)
{
    node *p=n;
    if (n != NULL)
    {
        p = n;
        n = n->right;
    }
    while (n->left != NULL)
    {
        p = n;
        n = n->left;
    }
    return p;
}

void delete_node(int data)
{
    node *parent = NULL;
    if (parent = search(root, data))
    {

        if (data > parent->data)
        {
            x = parent->right;
        }
        else if (data < parent->data)
        {
            x = parent->left;
        }
        else if (data == parent->data)
        {
            x = parent;
        }
        // case 1 : 0 child
        if (x->left == NULL && x->right == NULL)
        {
            if (parent->right == x)
            {
                parent->right = NULL;
                free(x);
                x = NULL;
            }
            else
            {
                parent->left = NULL;
                free(x);
                x = NULL;
            }
        }

        // case 2.1: 1 left child, 0 right child
        else if (x->left != NULL && x->right == NULL)
        {

            if (parent->right == x)
            {
                parent->right = x->left;
                (x->left)->parent=parent;
                free(x);
                x = NULL;
            }
            else
            {
                parent->left = x->left;
                (x->left)->parent = parent;
                free(x);
                x = NULL;
            }
        }

        // case 2.2: 0 left child, 1 right child
        else if (x->left == NULL && x->right != NULL)
        {

            if (parent->right == x)
            {
                parent->right = x->right;
                free(x);
                x = NULL;
            }
            else
            {
                parent->left = x->right;
                free(x);
                x = NULL;
            }
        }

        // case 3: 2 children
        else
        {
            if (parent->right == x)
            {
                x = parent->right;
            }
            else if (parent->left == x)
            {
                x = parent->left;
            }
            else
            {
                parent = x;
            }
            node *succ_p = findSuccessor(x);
            if(succ_p==x){
                swap((succ_p->right)->data, x->data);
                succ_p->right=NULL;
                x=x->right;
                free(x);
            }
            else{
                swap(x->data, (succ_p->left)->data);
                x=succ_p->left;
                succ_p->left=NULL;
                free(x);
                x=NULL;
            }
            
            // swap((succ_p->left)->data, x->data);
            // succ_p->left = NULL;
            // free(succ_p->left);
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

int main()
{
    insert_node(50);
    insert_node(30);
    insert_node(40);
    insert_node(70);
    insert_node(60);
    insert_node(20);
    insert_node(59);
    inorder(root);
    cout << endl;

    // delete_node(20);
    // inorder(root);
    // cout << endl;

    // delete_node(60);
    // inorder(root);
    // cout << endl;

    // delete_node(30);
    // inorder(root);
    // cout << endl;

    delete_node(50);
    inorder(root);
    cout << endl;

    // delete_node(79);
    // inorder(root);
    // cout << endl;

    return 0;
}