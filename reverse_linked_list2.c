#include <stdio.h>

void createnode();
void insertFirst();
void insertLast();
void display();
void reverse();

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

int counter;
node *start, *last, *temp;

void main(){
//	createnode();
	insertFirst();
	insertLast();	
	insertLast();	
	insertLast();	
	insertLast();
	reverse();
	display();
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

void reverse(){
	node *temp,*first,*end;
	//[0,1,2,3,4]
	temp = start -> next;
	first = start;
	end = start -> next->next;
	
	while(temp != NULL){
//		printf("%d %d %d\n ",temp->data,first->data,end->data);
	    end = first;
	    first = temp;
	     temp = temp-> next;
	    first -> next = end;
	   
	}
	start = first;
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
