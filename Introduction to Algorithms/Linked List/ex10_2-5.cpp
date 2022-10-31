#include <bits/stdc++.h>
using  namespace std;

typedef struct link_node{
    string key;
    // int value;
    struct link_node* next;
}node;

node *senti, *temp;


void insert_node(){
    node *tmp = (node *)malloc(sizeof(node));
    cout << "hello";
    
    temp=tmp;
    temp->next = senti->next;
    senti->next = temp;
    cout<<"Enter key: ";
    cin>>temp->key;
    // temp->value=1;
    return;
}

void delete_node(){
    string ele;
    cout<<"Enter ele to delete: ";
    cin>>ele;
    node * i=senti, *j;
    while(i->key!=ele && i->next!=senti){
        j=i;
        i=i->next;
    }
    if(i->key==ele){
        j->next=i->next;
        free(i);
        i=NULL;
        cout<<"Element delete"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

}

void search(){
    string ele;
    cout << "Enter ele to search: ";
    cin >> ele;
    node *i = senti, *j;
    while (i->key != ele && i->next != senti)
    {
        j = i;
        i = i->next;
    }
    if (i->key == ele)
    {
        cout<<"Element found"<<endl;
    }
    else{
        cout << "Element not found" << endl;
    }
}

int main(){
    senti = (node*)malloc(sizeof(node));
    senti->next=senti;
    senti->key="-1";
    // senti->value=-1O;   
    insert_node();
    insert_node();
    insert_node();
    search();
    delete_node();
    search();

    return 0;
} 