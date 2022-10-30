#include <bits/stdc++.h>
using  namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}node;

node *temp, *head;

void createNode(){
    temp=(node*)malloc(sizeof(node));
    if(head==NULL){
        head=temp;
    }
    cout<<"Enter element: ";
    cin>>temp->data;
}

void deleteFirst(){
    node *temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
}

void insertFirst(){
    createNode();
    temp->next=head;
    head=temp;
}

void display(){
    for(node* i=head; i->next!=NULL; i=i->next){
        cout<<i->data<<endl;
    }
}

int main(){
    createNode();
    insertFirst();
    insertFirst();
    deleteFirst();
    display();
    return 0;
} 