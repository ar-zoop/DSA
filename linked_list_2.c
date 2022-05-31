#include <stdio.h>
#include <stdlib.h>
void createnode();
void insertFirst();
void insertLast();
void insertAnywhere();
void display();
void deleteFirst();
void deleteLast();
void deleteAnywhere();

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *start, *last, *temp;
int counter;

void main(){
	int choice;
		printf("Choose 1) create node\n2) insert at first\n3)insert at last\n5)display \n6)delete first \n7)delete last \n8) Delet anywhere:  ");
	
	while(1){
		
		scanf("%d",&choice);
		switch(choice){
			case 1:
				createnode();
				break;
			case 2:
				insertFirst();
				break;
			case 3:
				insertLast();
				break;
			
			case 5:
				display();
				break;
			case 6: 
				deleteFirst();
				break;
			case 7:
				deleteLast();
				break;
				
			case 8:
				deleteAnywhere();
				break; 
				
			default:
				printf("Enter correct choice!");
		}
	}
}

void createnode(){	
	temp=(node*)malloc(sizeof(node));
	printf("Enter value: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if (start==NULL){
		start=temp;
		last=temp;	
	}
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

void display(){
	node *p;
	int i;
	p=start;
	for (i=1; i<=counter;i++){
		printf("\n%d",p->data);
		p=p->next;
	}
}

void deleteFirst(){
	int i;
	node *p, *temp;
	
	if(start==NULL)
		printf("not possible");	
	
	else if (start==last){
		free(start);
		start=NULL;
		last=NULL;
		counter--;
	}
	else{
		
		temp=start;//address saved
		start=start->next;//
		free(temp);
		temp=NULL;//address nulled
        
		counter--;
	}

}

void deleteLast(){
	if(start==NULL)
		printf("not possible");	
	
	else if (start==last){
		free(start);
		start=NULL;
		last=NULL;
		counter--;
	}
	else{
		node *p;
		p=start;
	
		while (p->next!=last){
			p=p->next;
		}
		free(last);
		last=p;
		last->next=NULL;
		counter--;
		p=NULL;
	}
}

 void deleteAnywhere(){
 	node *p, *temp;
 	int n;
 	printf("Enter the node number you want to delete: ");
 	scanf("%d", &n);
 	if (counter<n){
 		printf("Not possible");
	 }
	else if (counter==n)
		deleteLast();
	else{
		int i;
		temp=start;
		for (i=1;i<n;i++){
			p=temp;
			temp=temp->next;	
		}	
		p->next=temp->next;
		free(temp);
		temp=NULL;
		counter--;
	}
 }



