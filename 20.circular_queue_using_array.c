#include <stdio.h>
#define MAX 5

void enqueue(int);
void dequeue();
void display();

int f=-1,r=-1,q[MAX];

int main(){
	int ch,x;
	printf("your choices:\n1)Enqueue\n2)Dequeue\n3)Display: ");
	while(1){
		scanf("%d",&ch);
		switch(ch){
			case 1: 
				printf("Enter value: ");
				scanf("%d", &x);
				enqueue(x);
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

void enqueue(int data){
	if (((r+1)%MAX)==f)
		printf("Overflow");
	else if(r==MAX-1 && f!=0){
		r=0;
		q[r]=data;
	}
	else if(f==-1){
		f=r=0;
		q[r]=data;
	}
	else{
		q[++r]=data;
	}
}

void dequeue(){	
	if(f==-1)
		printf("Underflow\n");
	else if(r==f){
		printf("Value dequeued= %d\n",q[f]);
		r=f=-1;
	}		
	else if(f==MAX-1){
		printf("Value dequeued= %d\n",q[f]);
		f=0;
	}
	else{
		printf("Value dequeued= %d\n",q[f]);
		f++;
	}
}

void display(){
	if(f==-1)
		printf("Underflow");
	else{
		int i;
		for (i=f;i!=r;i=(i+1)%MAX){
			printf("%d ",q[i]);
		}
		printf("%d ",q[r]);
	}
}

