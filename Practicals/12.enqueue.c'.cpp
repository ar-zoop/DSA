#include <stdio.h>
#define MAX 20

void enqueue(int);
void dequeue();
void display();

int f=-1,r=-1,q[MAX];

int main(){
	int ch,x;
	printf("your choices:\n1)Enqueue\n2)Dequeue\n3)Peek\n4)Display: ");
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
			
			case 4:
				display();
				break;
			default:
				printf("Invalid choice!");
		}
	}
	return 0;
} 

void enqueue(int data){
	if (r==MAX-1)
		printf("Overflow");
		return;
	else if(f==-1 && r==-1)
		f=r=0;
	else
		r++;
		
	q[r]=data;
}

void dequeue(){	
	if(f==-1)
		printf("Underflow");
	else if(r==f)
		r=f=-1;
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
		for (i=f;i<=r;i++){
			printf("%d ",q[i]);
		}
	}
}

