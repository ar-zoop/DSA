
#include <bits/stdc++.h>
using namespace std;

typedef struct xor_node{
    int data;
    //XOR-ed prev and next pointers
    struct xor_node* np;
}node;

node *create_node(){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->np = NULL;
    return tmp;
}


node* XOR(node *prev, node *next){
    return (node*)((int)prev ^ (int)next);
}

//ARZOO CODE
void insert_node(node **head, node**tail, int data){
    node *new_node = create_node();
    
    new_node->data = data;
    new_node->np=*head;
    if (*tail == NULL){
        *tail = new_node;
        // cout<<"added tail"<<endl;
    }
    if(*head != NULL){
        // cout<<"added head"<<endl;
        new_node->np = XOR(*head, NULL);
        (*head)->np=XOR((*head)->np,new_node);
    }
    *head=new_node;
    // cout<<head->data<<endl;
    // cout<<" in fucntion: head "<<(*head)->data<<"tail "<<(*tail)->data<<endl;
    // return head;
}


/*
//YASH CODE
void insert_node(node **head, int data){
    // insertion at starting of the linked list
    node *new_node = create_node();
    new_node->key = data;

    new_node->np = XOR(*head,NULL);

    if(*head !=NULL){
        node *next = XOR((*head)->np, NULL);
        (*head)->np = XOR(new_node, next);
    }
    *head = new_node;
    cout << "insertion done!\n" ;
    return;
}

//ARZOO CODE
void traversal(node *head){
    //initialising pointers
    cout<<head->data<<" ";
    node*prev=head;
    node *curr=prev->np;
    cout<<curr->data<<" ";
    node *next;    
    next=XOR(curr->np,prev);
    
    //moving pointers ahead
    while(next!=NULL){
        prev=curr;
        curr=next;
        cout<<curr->data<<" ";
        next=XOR(curr->np,prev);
    }
    return;
}

*/

// YASH CODE
void traversal(node *head, node *tail, bool from)
{
    // from = 1 <= traverse from front;
    // from = 0 <= traverse from back;
    node *prev = NULL, *next;
    if (from)
    {
        node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            next = XOR(prev, curr->np);
            prev = curr;
            curr = next;
        }
        cout << endl;
    }
    else
    {
        node *curr = tail;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            next = XOR(prev, curr->np);
            prev = curr;
            curr = next;
        }
        cout << endl;
    }
}

//YASH CODE
void delete_node(node **head, node**tail)
{
    if (*head == NULL)
        return;

    node *next = XOR(NULL, (*head)->np);
    if (next == NULL)
    {
        *head = NULL;
        *tail=NULL;
        return;
    }
    next->np = XOR(*head, next->np);
    (*head)->np = NULL;
    // node *more_next = XOR(next, next->np);
    free(*head);
    *head = next;
    return;
}

//ARZOO CODE
node * search(node * head, int data) {
    if (head == NULL)
    {
        cout << "Underflow" << endl;
    }
    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != NULL && curr->data != data)
    {
        // cout << curr->data << " ";
        next = XOR(prev, curr->np);
        prev = curr;
        curr = next;

    }
    return curr;
}
/*
//ARZOO CODE
void delete_node_between(node *head, int data){
    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != NULL && curr->data != data)
    {
        next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    next = XOR(prev, curr->np);
    // cout<<"Current positions: "<< prev->data<<" "<<curr->data<<" "<<next->data<<endl;
    prev->np=XOR(XOR(prev->np,curr),next);
    next->np=XOR(XOR(next->np,curr),prev);
    free(curr);
    curr=NULL;
}
*/
void reverse(node **head, node **tail ){
    swap(*tail, *head);
}


/*
//YASH CODE

void delete_mid(node *head, int data)
{
    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != NULL && curr->data != data)
    {
        next = XOR(prev, curr->np);
        prev = curr;
        curr = next;
    }
    next = XOR(prev, curr->np);
    // prev -> pointer before the number to delete.
    if (curr == NULL)
        cout << "No element found !!\n";

    node *x = prev;
    prev->np = XOR(prev->np, XOR(curr, next));
    next->np = XOR(next->np, XOR(x, curr));
    free(curr);
    curr = NULL;
    return;
}
*/

int main(){
    vector<int> datas = {100,200,300,400,500};
    int n= datas.size();    
    node *head = NULL, *tail=NULL;
    for(int i=0 ; i<n ;i++){
        insert_node(&head, &tail, datas[i]);
        // cout<<"head"<<" "<<head<<" tail "<<tail<<endl;
    }
    // traversal(head);
    delete_node(&head, &tail);
    // traversal(head);
    // if(search(head, 0)!=NULL) cout<<"element found"<<endl;
    // else cout<<"Element not found";
    // delete_node_between(head,300);
    // traversal(head);
    traversal(head, tail, true);
    reverse(&head, &tail);
    // traversal(head);
    traversal(head, tail, true);
    traversal(head, tail, false);
    return 0;

    
}
