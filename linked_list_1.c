#include <stdio.h>
#include <stdlib.h>

void createnode();
void insertFirst();
void insertLast();
void insertAnywhere();
void display();

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *start, *last, *temp;
int counter;

int main(){
	int choice;
	while(1){
		
		printf("Choose 1) insert at first\n2)insert at last\n3)insert anywhere\n4)display\n5) Exit: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insertFirst();
				break;
			case 2:
				insertLast();
				break;
			case 3:
				insertAnywhere()	;
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Enter the right choice!");
		}
	}
}

void createnode(){	
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	counter++;
}
	

void insertFirst(){
	createnode();	
	if (start==NULL){
		start=temp;
		last=temp;
	}
	else{
		temp->next=start;
		start=temp;
	}
}

void insertLast(){
	createnode();
	if (start==NULL){
		start=temp;
		last=temp;
	}
	else{
		last->next=temp;
		last=temp;
		last->next=NULL;
	}
}

void insertAnywhere(){
	createnode();
	if (start==NULL){
		start=temp;
		last=temp;
	}
	else{
		int n,i;
		
		printf("Enter where to insert: ");
		scanf("%d", &n);
		if (counter<n){
			printf("not possible");
			printf("counter=%d, position=%d", counter, n);
		}
		else{
			if(n==counter){
				last->next=temp;
				last=temp;
			}
			else{
				node *p,*q;
				p=start;
				for(i=1;i<n-1;i++){
					p=p->next;
				}				
			
		
//method 1 using 2 poointers
			q=p->next;
			temp->next=q;
			p->next=temp;

//method 2 using 1 pointer
//			temp->next=p->next;
//			p->next=temp;
		}
}
	}
}


void display(){
	node *p;
	int i;
	p=start;
	for (i=1; i<=counter;i++){
		printf("\n%d\n",p->data);
		p=p->next;
	}
}
