#include <stdio.h>
#include <stdlib.h>

typedef struct linknode{
	struct linknode *prev;
	int data;
	struct linknode *next;
}node;

node *last,*start,*temp;
int counter;

void insert_first();
void insert_last();
void insert_anywhere();
void createnode();
void display();


int main(){
	int ch;
	printf("Your choices:\n1)Insert first\n2)Insert last\n3)Insert anywhere\n4)Display: ");
	while(1){
		printf("\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_first(); break;
			case 2: insert_last(); break;
			case 3: insert_anywhere(); break;
			case 4: display();break;
			default: printf("Invalid choice!");
		}
	}
	return 0;
}


void insert_first(){
	createnode();
	if(start==NULL)
		start=last=temp;
	else{
		temp->next=start;
		start->prev=temp;
		start=temp;
	}
	
}

void insert_last(){
	createnode();
	if(start==NULL)
		start=last=temp;
	else{
		last->next=temp;
		temp->prev=last;
		last=temp;
		last->next=NULL;
	}
}

void insert_anywhere(){
	int n;
	printf("Where do you want to add the node: ");
	scanf("%d",&n);
	if(n>counter+1)
		printf("Not enough nodes exist\n");
	else if(n==1)
		insert_first();
	else if(n==counter+1)
		insert_last();
	else{
		createnode();
		node *p=start,*q;
		int i;
		for(i=0;i<n-1;i++){
			q=p;
			p=p->next;
		}
		q->next=temp;
		temp->next=p;
		p->prev=temp;
		temp->prev=q;
	}
}

void createnode(){
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d", &temp->data);
	temp->next=NULL;
	counter++;
}

void display(){
	node *p=start;
	int i;
	for (i=0;i<counter;i++){
		printf("%d ",p->data);
		p=p->next;
	}
}
