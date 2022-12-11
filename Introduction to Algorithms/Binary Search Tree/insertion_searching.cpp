#include <bits/stdc++.h>
using  namespace std;

typedef struct tree_node
{
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
}

void search(node*n, int data){
    while (n != NULL && n->data != data)
    {
        if(n->data<data){
            n=n->right;
        }
        else{
            n=n->left;
        }
    }
    if(n!=NULL && n->data==data){
        cout<<"found"<<endl;
        return;
    }
    cout<<"not found"<<endl;
    return;
}

int main(){
    insert_node(50);
    insert_node(30);
    insert_node(40);
    insert_node(70);
    insert_node(60);
    insert_node(20);
    insert_node(59);
    search(root,50);
    search(root, 60);
    search(root, 20);
    search(root, 59);
    search(root, 25);
    return 0;
} 