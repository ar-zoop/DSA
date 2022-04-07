#include <stdio.h>
#include <stdlib.h>

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *top,*temp;

void createnode();
void insert();
void display();
void deletion();
void peek();

int main(){
	printf("your choices are:\n1)Push\n2)Pop\n3)Peek\n4)Display: ");  
	int ch;
	while(1){
		printf("\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:insert();break;
			case 2:deletion();break;
			case 3:peek();break;
			case 4:display();break;
			default:printf("Invalid choice!");
		}
	}
	return 0;
}

void createnode(){
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d", &temp->data);
	temp->next=NULL;
}

void insert(){
	createnode();
	if(top==NULL)
		top=temp;
	else{
		temp->next=top;
		top=temp;
		
	}
}

void display(){
		if (top==NULL)
			printf("Underflow\n");
		else{
			node *p=top;
			while(p!=NULL){
				printf("%d ",p->data);
				p=p->next;
			}
		}
}

void deletion(){
	if (top==NULL)
		printf("Underflow\n");
	else{
		node*p=top;
		top=top->next;
		free(p);
		p=NULL;
	}
}
void peek(){
	if (top==-1)
		printf("Underflow\n");
	else{
		printf("%d",top->data);
	}
}
