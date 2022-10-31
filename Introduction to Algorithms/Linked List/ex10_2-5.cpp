#include <bits/stdc++.h>
using  namespace std;

typedef struct LinkNode
{   struct LinkNode *next;
    int data;
} node;

node *temp, *senti;

void createnode()
{
    temp = (node *)malloc(sizeof(node));
}

void insert(int ele)
{
    createnode();
    temp->data = ele;
    temp->next = senti->next;
    senti->next = temp;
}

node* search(int ele){
    node *forward=senti;
    node* backup;
    while(forward->next!=senti && forward->data!=ele){
        backup=forward;
        forward = forward->next;
    }
    if (forward->data == ele)
    {
        cout<<"element found"<<endl;
        return backup;
    }
    else{
        cout<<"element not found"<<endl;
        return NULL;
    }
}

void delete_node(int ele){
    temp=search(ele);
    if(temp==NULL){
        cout<<"element not found"<<endl;
    }
    else{
        node*to_free;
        to_free=temp->next;
        temp->next=to_free->next;
        free(to_free);
        to_free=NULL;
    }
}

void display()
{
    node *tmp = senti->next;
    while (tmp != senti)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main(){
    senti = (node *)malloc(sizeof(node));
    senti->next = senti;
    insert(1);
    display();
    search(1);
    insert(2);
    search(2);
    display();
    delete_node(1);
    search(1);
    display();
    return 0;
} 