#include<stdio.h>
void create_node();
typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *start, *temp;
	
void main(){

	
}

void create_node(){
	temp=(node*)malloc(1*sizeof(node));
	printf("Enter new value: ");
	scanf("%d", &temp->data);
	temp->next=NULL: //why?? what value does it already have??
	
}

void insertFirst(){
	
}

void insertLast(){
	
}

void insertAnywhere(){
	
}
