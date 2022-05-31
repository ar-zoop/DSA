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
	node *p,*q,*r,*temp;
	r=start;
	q=r->next;
	p=q->next;
	q->next=r;
	//reversing
	while(p!=NULL){
//		printf("hi");
		r=q;
		q=p;
		p=p->next;
//		printf("hello");
		//link reverse
		q->next=r;
//		printf(" ");
//		printf("%d",start->data);
//		printf("%d", last->data);
	}
	
	//last step
	start->next=NULL;

	temp=last;
	last=start;
	start=temp;

//	printf("%d",start->data);
//	printf("%d", last->data);
	
	temp=NULL;
	p=NULL;
	q=NULL;
	r=NULL;
//	printf("no");
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
