#include <bits/stdc++.h>
using  namespace std;

typedef struct linkNode{
    int data;
    struct linkNode *prev;
    struct linkNode *next;
}node;

node *temp;

void create_node(){
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->prev=NULL;
    temp->data=-1;
}

void insert(int data, node * senti){
    create_node();
    temp->data=data;
    senti->prev->next=temp;
    temp->prev=senti->prev;
    senti->prev=temp;
    temp->next=senti;
}

void display(node*senti){
    node *i;
    for(i=senti->next; i!=senti; i=i->next){
        cout<<i->data<<" ";
    }
    cout<<endl;
}

node * union_operator(node* s1, node *s2){
    s1->prev->next=s2->next;
    s2->next->prev=s1->prev;
    s1->prev=s2->prev;
    s2->prev->next=s1;
    return s1;
}

int main(){
    node* s1=(node*)malloc(sizeof(node));
    s1->next=s1;
    s1->prev=s1;
    node* s2=(node*)malloc(sizeof(node));
    s2->next=s2;
    s2->prev=s2;
    insert(10, s1);
    insert(20, s1);
    insert(30, s1);
    insert(100,s2);
    insert(200, s2);
    insert(300, s2);
    display(s1);
    display(s2);
    s1=union_operator(s1,s2);
    display(s1);
    return 0;
} 