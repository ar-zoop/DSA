#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void push();
void pop();
void peek();
void display();

int stack[MAX],top=-1;

int main(){
	int ch;
	printf( "Choices are:\n1)Push\n2)Pop\n3)Peek\n4)Display\n5)Exit: ");
	while(1){
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)	{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("BYE!");
				exit(0);
			default:
				printf("Invalid choice!");
		}
	}
	return 0;
}

void push(){
	if (top==MAX-1)
		printf("Overflow\n");
	else{
		printf("Enter the value of element: ");
		scanf("%d", &stack[++top]);
	}
}

void peek(){
	if (top==-1)
		printf("Underflow\n");
	else{
		printf("%d\n", stack[top]);
	}
}

void display(){
	if (top==-1)
		printf("Underflow\n");
	else{
		int i=top;
		for (i=top;i>=0;i--)
			printf("%d ",stack[i]);
	}
}

void pop(){
	if (top==-1)
		printf("Underflow\n");
	else{
		printf("Element popped= %d ",stack[top--]);
	}
	
}
