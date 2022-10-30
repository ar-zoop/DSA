#include <bits/stdc++.h>
using  namespace std;

typedef struct LinkedNode{
    int data;
    struct LinkedNode* next;
}node;

node *head, *temp;

bool isempty(){
    if(head==NULL){
        // cout<<head;
        return true;
    }
    return false;
}

void push(){
    temp=(node*)malloc(sizeof(node));
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
    cout<<"Enter the element: ";
    cin>>temp->data;
    
}

void pop(){
    if(!isempty()){
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    else{
        cout<<"Underflow"<<endl;
    }
}

void display(){
    for(node* i=head; i->next!=NULL; i=i->next){
        cout<<i->data<<endl;
    }
}

void peek(){
    if(!isempty()){
        cout<<head->data<<endl;
    }
    else{
        cout<<"Underflow";
    }
}


int main(){
    push();
    push();
    push();
    pop();
    pop();
    pop();
    pop();
    // display();
    peek();
    return 0;
} 