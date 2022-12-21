#include <bits/stdc++.h>
using  namespace std;

typedef struct RB_tree_node
{
    struct RB_tree_node *parent;
    struct RB_tree_node *left;
    struct RB_tree_node *right;
    int color;//0= black, 1= red
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
    temp->parent=NULL;
    temp->color=1;
}

void create_nil_node(){
    // RB_create_node();
    temp = (node *)malloc(sizeof(node));
    temp->color=0;
    temp->data=-1;
    y=temp;

}

void right_rotation(node *p)
{
    node *q = p->left;
    node *hold = q->right;
    q->right = p;
    if(hold==NULL){
        p->left = NULL;
    }
    else{
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
    if(hold==NULL){
        p->right=NULL;
    }
    else{
        p->right = hold;
    }
    if (p == root)
    {
        root = q;
    }
    return;
}

void RB_insert_fixup(node *z){
    while((z->parent)->color==1){
        if(((z->parent)->parent)->right==z->parent){
            if ((((z->parent)->parent)->left)!=NULL && (((z->parent)->parent)->left)->color == 1)
            {
                (((z->parent)->parent)->left)->color=0;
                (z->parent)->color=0;
                z=z->parent->parent;

            }
            else{
            if(z==z->parent->left){
                z=z->parent;
                right_rotation(z);
            }
            
            z->parent->color=0;
            if (z->parent->parent != root)
                z->parent->parent->color = 1;
            left_rotation(z->parent->parent);
        }
        }
        else{
            if ((((z->parent)->parent)->right)!=NULL &&  (((z->parent)->parent)->right)->color == 1)
            {
                (((z->parent)->parent)->right)->color = 0;
                (z->parent)->color = 0;
                z = (z->parent)->parent;
            }
            else {
                if (z==z->parent->right)
                {
                    z=z->parent;
                    left_rotation(z);
                }
            
                
                z->parent->color=0;
                if (z->parent->parent != root)
                    z->parent->parent->color = 1;
                right_rotation(z->parent->parent);
            
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
        root->color=0;
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

int main(){
    // create_nil_node();
    RB_insert_node(41);
    inorder(root);cout<<endl;
    // cout<<y->data<<endl;
    RB_insert_node(38);
    inorder(root);cout<<endl;
    RB_insert_node(31);
    inorder(root);cout<<endl;
    RB_insert_node(12);
    inorder(root);cout<<endl;
    RB_insert_node(19);
    inorder(root);cout<<endl;
    RB_insert_node(8);
    inorder(root);cout<<endl;
    return 0;
} 