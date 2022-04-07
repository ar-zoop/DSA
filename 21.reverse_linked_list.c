#include <stdio.h>
#include<stdlib.h>

typedef struct linknode{
	int data;
	struct linknode *next;
}node;

node *temp,*start,*last;
int counter;

void createnode();
void insert();
void reverse();
void display();

int main(){
	int n;
	printf("How many nodes do you want: ");
	scanf("%d",&n);
	while(n--){
		insert();
	}
	printf("Before reversing:\n");
	display();
	reverse();
	printf("\nAfter reversing:\n");
	display();
}

void insert(){
	createnode();
	if(start==NULL)
		start=last=temp;
	else{
		last->next=temp;
		last=temp;
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

void reverse(){
	node *p,*q,*r;
	r=start;
	q=r->next;
	p=q->next;
	q->next=r;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	start->next=NULL;
	p=start;
	start=last;
	last=p;
	p=q=r=NULL;
}
