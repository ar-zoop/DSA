#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct linknode{
	int data;
	struct linknode* next;
}node;

void create_node();
void add_edge(int, int);
void display(int);

node* root;
node *temp;
node **head;
node ** end;

int  main(){
	int size=4,i;
//	printf("Enter number of vertices: ");
//	scanf("%d",&size);	
	head= new node*[size];
	end= new node*[size];
	for (i=0;i<size;i++){
		*(head+i)=NULL;
		*(end+i)=NULL;
	}
	
	add_edge(2,3);
	add_edge(1,2);
	add_edge(1,3);
	add_edge(2,4);
	add_edge(4,3);
	display(size);
	return 0;
}

void create_node(){
	temp=(node*)malloc(sizeof(node));
	if(root==NULL){
		root=temp;
		root->next=NULL;
	}
}

void add_edge(int a, int b){
	//adding node 1 to the list
	create_node();
	temp->data=a;
	temp->next=NULL;
	int i=b-1;
	if (*(head+i)==NULL) {
        *(head+i)=temp;
        *(end +i)=temp;
    }
    else{
    	(*(end+i))->next=temp;
    	*(end+i)=temp;
	}
            
	//adding node 2 to list
	create_node();
	i=a-1;
	temp->data=b;
	temp->next=NULL;
	if (*(head+i)==NULL) {
        *(head+i)=temp;
        *(end +i)=temp;
    }
    else{
    	(*(end+i))->next=temp;
    	*(end+i)=temp;
	}
}

void display(int size){
	 for (int i = 0; i < size; ++i) {
        node* temp = *(head + i);
  
        // Linked list number
        cout << i+1 << "-->\t";
  
        // Print the Linked List
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
  
        cout << '\n';
    }
}
