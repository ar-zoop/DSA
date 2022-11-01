
#include <bits/stdc++.h>
using namespace std;

typedef struct link_node{
    int key;
    struct link_node *prev;
    struct link_node *next;
}Node;

Node *create_node(){
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = -1;
    node->prev =NULL;
    node->next =NULL;
    return node;
}

void insert_node(Node *Sentinel, int ele){
    Node *new_node = create_node();
    new_node->key  = ele;
    new_node->prev = Sentinel->next->prev;
    new_node->next = Sentinel->next;
    Sentinel->next = new_node;
}

void display(Node *Sentinel){
    Node *tmp = Sentinel->next;
    while(tmp != Sentinel){
        cout << tmp->key <<" ";
        tmp = tmp->next;
    }
    cout <<"\n";
    return;
}

Node *union_operation(Node *senti_1, Node *senti_2){
    Node *temp=senti_1->next;
    senti_1->next=senti_2->next;
    senti_2->next->prev=senti_1;
    senti_2->prev->next=temp;
    temp->prev=senti_2->prev;
    return senti_1;
}


int main(){
    Node *senti_1 = create_node();
    Node *senti_2 = create_node();

    senti_1->prev = senti_1, senti_1->next=senti_1;
    senti_2->prev = senti_2, senti_2->next=senti_2;

    cout << "\ncreating 1st linked list...\n";
    insert_node(senti_1,100);
    insert_node(senti_1,200);
    insert_node(senti_1,300);
    
    display(senti_1);

    cout << "\ncreating 2nd linked list...\n";
    insert_node(senti_2,11);
    insert_node(senti_2,22);
    insert_node(senti_2,33);
    
    display(senti_2);

    cout << "\napplying union on 2 linked list....";
    senti_1 = union_operation(senti_1,senti_2);

    cout << "\nnew linked list after union...\n";
    display(senti_1);
    free(senti_2);
    senti_2=NULL;
    return 0;
}
