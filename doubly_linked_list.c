#include <stdio.h>
#include <stdlib.h>

void insert_first();
void insert_last();
void insert_anywhere();
void create_node();
void display();
void delete_first();
void delete_last();
void delete_anywhere();

typedef struct linknode{
	struct linknode  *prev;
	int data;
	struct linknode *next;
}node;

int count;
node *temp,*last, *first;

int main(){
	printf("Choices:\n1. Insert at first\n2. Insert at last\n3. Insert anywehre\n4. Exit\n5. Display\n6. Delete at first\n7. Delete at last\n8. Delete anywehre\n");
	while(1){
		int ch;
		printf("Enter choice: ")	;
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert_first();
				break;
			case 2:
				insert_last()	;
				break;
			case 3: 
				insert_anywhere();
				break;
			case 4:
				exit(0);
				break;
			case 5:
				display();
				break;
			case 6:
				delete_first();
				break;
			case 7:
				delete_last()	;
				break;
			case 8: 
				delete_anywhere();
				break;
			default:
				printf("Enter correct choice!\n");
		}
	}
	return 0;
}

void insert_first(){
	create_node();
	if(last==NULL){
		last=temp;
		first=temp;
	}
	else{
		first->prev=temp;
		temp->next=first;
		first=temp;
	}
}

void insert_last(){
	create_node();
	if(last==NULL){
		last=temp;
		first=temp;
	}
	else{
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}

void insert_anywhere(){
	int n;	
	printf("Where do you want to enter the node: ");
	scanf("%d", &n);
	if(last==NULL){
		last=temp;
		first=temp;
	}
	else if (n==(count+1)){
		insert_last();
	}
	else if((count)<n){
		printf("Not possible");
	}
	else if(n==1){
		insert_first();
	}
	else{
		int i;
		node *q,*p;
		create_node();
		q=first;
		for (i=0;i<n-1;i++){
			p=q;
			q=q->next;
		}
		temp->prev=p;
		temp->next=q;
		p->next=temp;
		q->prev=temp;
	}
	
}

void create_node(){
	temp=(node*)malloc(sizeof(node));
	printf("Enter data: ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;	
	count++;
}

void display(){
	temp=first;
	while(temp->next!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}

void delete_first(){
	if(last==NULL){
		printf("Underflow");
		count++;
	}
	else if (first==last){
		free(last);
		first=NULL;
		last=NULL;
	}
	else{
		temp=first;
		first=first->next;
		first->prev=NULL;
		free(temp);
		temp=NULL;
	}
	count--;
}

void delete_last(){
	if(last==NULL){
		printf("Underflow");
		count++;
	}
	else if (first==last){
		free(last);
		first=NULL;
		last=NULL;
	}
	else{
		temp=last;
		last=last->prev;
		last->next=NULL;
		free(temp);
		temp=NULL;
		
	}	
	count--;
}

void delete_anywhere(){
	if(last==NULL)
		printf("Underflow\n");
	
	else{
		int n;
		printf("What node number do you want to delete: ");
		scanf("%d", &n);
		if(n==1)
			delete_first();
		else if(n==count)
			delete_last();
		else if(n>count)
			printf("Underflow\n");
		else{
			int i;
			node *p,*q,*r;
			q=first;
			for (i=0;i<n-1;i++){
				p=q;
				q=q->next;				
			}
			r=q->next;
			p->next=r;
			r->prev=p;
			free(q);
			q=NULL;
		}
		
	}
	
}
