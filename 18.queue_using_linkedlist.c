#include <stdio.h>
#include <stdlib.h>

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *f,*r,*temp;

void enqueue();
void dequeue();
void display();
void createnode();

int main(){
	printf("your choices are:\n1)Enqueue\n2)Dequeue\n3)Display: ");  
	int ch;
	while(1){
		printf("\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			default:printf("Invalid choice!");
		}
	}
	return 0;
}

void enqueue(){
	createnode();
	if(f==NULL)
		f=r=temp;
	else{
		r->next=temp;
		r=temp;
	}
}
void dequeue(){
	node *p=f;
	f=f->next;
	free(p);
	p=NULL;
}
void display(){
	if(f==NULL){
		printf("Underflow");
	}
	else{
		node *p=f;
		while(p!=r){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("%d ",r->data);
	}
}
void createnode(){
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
}
