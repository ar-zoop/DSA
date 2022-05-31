#include <stdio.h>
#include <stdlib.h>

void insert_first();
void insert_last();
void insert_anywhere();
void delete_first();
void delete_last();
void delete_anywhere();
void createnode();
void display();

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *start,*last,*temp;
int counter;

int main(){
	int ch;
	printf("Your choices:\n1)Insert first\n2)Insert last\n3)Insert anywhere\n4)Delete first\n5)Delete last\n6)Delete anywhere\n7)Display: ");
	while(1){
		printf("\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_first(); break;
			case 2: insert_last(); break;
			case 3: insert_anywhere(); break;
			case 4: delete_first();break;
			case 5: delete_last(); break;
			case 6: delete_anywhere(); break;
			case 7: display();break;
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
		start=temp;
	}
	
}

void insert_last(){
	createnode();
	if(start==NULL)
		start=last=temp;
	else{
		last->next=temp;
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
	}
}

void delete_first(){
	node *p;
	if (counter==0)
		printf("Underflow");
	else{
		p=start;
		start=start->next;
		free(p);
		p=NULL;
		counter--;
	}
}

void delete_last(){
	if (counter==0)
		printf("Underflow");
	else{
		node *p=start;
		while(p->next!=NULL)
			p=p->next;
		last=p;
		free(last);
		p=NULL;
		free(p);
		counter--;
	}
}

void delete_anywhere(){
	if (counter==0)
		printf("Underflow");
	else{
		int n;
		printf("Enter what node to delete: ");
		scanf("%d",&n);
		if(n==1)
			delete_first();
		else if(n==counter)
			delete_last();
		else if(n>counter)
			printf("Node does not exist");
		else{
			int i;
			node *p=start,*q;
			for(i=0;i<n-1;i++){
				q=p;
				p=p->next;
			}
			q->next=p->next;
			free(p);
			p=NULL;
			counter--;
		}
	}
}

void createnode(){
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d", &temp->data);
	if(start==NULL)
		start=last=temp;
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
