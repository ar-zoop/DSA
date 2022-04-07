#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();
void createnode();

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *last,*temp;

int main(){
	int ch,x;
	printf("your choices:\n1)Enqueue\n2)Dequeue\n3)Display: ");
	while(1){
		scanf("%d",&ch);
		switch(ch){
			case 1: 
				enqueue();
				break;
			case 2:
				dequeue();
				break;			
			case 3:
				display();
				break;
			default:
				printf("Invalid choice!");
		}
	}
	
	return 0;
}

void enqueue(){
	createnode();
	
			if(last==NULL){
		last=temp;
		temp->next=temp;
	}
	
	else{
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}
void dequeue(){
	if(last->next==last){
		free(last);
		last=NULL;
	}
	else{
		temp=last->next;
		last->next=temp->next;
		free(temp);
		temp=NULL;
	}
}
void display(){
	if(last==NULL)
		printf("UNderflow");
	else{
		temp=last->next;
		while(temp!=last){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d ",last->data);
	}
}

void createnode(){
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d", &temp->data);

	
}
