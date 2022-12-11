#include <bits/stdc++.h>
using  namespace std;

typedef struct tree_node {
    struct tree_node* left;
    int data;
    struct tree_node* right;
}node;

node *root, *temp, *x;

void create_node(){
    temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->right=NULL;
}

void insert_node(int data){
    create_node();
    temp->data=data;
    if (root == NULL)
    {
        root = temp;
        return;
    }
    else
    {
        x=root;
        while(x!=NULL){
            if(x->data<temp->data){
                if(x->right==NULL){
                    x->right=temp;
                    x=NULL;
                }
                else{
                    x=x->right;
                }

            }
            else{
                if(x->left==NULL){
                    x->left=temp;
                    x=NULL;
                }
                else{
                    x=x->left;
                }
            }
        }

    }
}

void inorder(node *n){
    if(n!=NULL){
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);

    }
}

void inorder_iterative(node *n){
    stack<node*> st;
    while(true){
        if(n!=NULL){
            st.push(n);
            n=n->left;
        }
        else if (!st.empty()){
            n=st.top();
            cout<<n->data<<" ";
            st.pop();
            n=n->right;
        }
        else{
            break;
        }
    }
}

void postorder(node *n){
    if(n!=NULL){
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<" ";
    }
}

void preorder(node *n){
    if (n != NULL)
    {
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
}

int main(){
    int t=7;
    int data;
    while(t--){
        cout<<"Enter data: "<<endl;
        cin>>data;
        insert_node(data);
    }
    cout<<"inorder: "; inorder_iterative(root);cout<<endl;
    cout<<"postorder: "; postorder(root); cout<<endl;
    cout<<"preorder: "; preorder(root);

    return 0;
} 