#include <stdio.h>
#include <stdlib.h>

//prototyping
void push(int);
void pop();
void display();
void peek();

//global variables
int stack[20];
int top=-1;

int main(){
	int x,y;
	while(1){
		printf("Enter the choice:\n");
		printf("1) Push\n2) Pop\n3) Display\n4) Peek\n5) Exit: ");
		scanf("%d",&x);
		
		switch(x){
			case (1):
				printf("Enter element to push: ");
				scanf("%d",&y);
				push(y);
				break;
				
			case (2):
				pop();
				break;
				
			case(3):
				display();
				break;
			
			case(4):
				peek();
				break;
				
			case(5):
				exit(0);
				break;
			
			default:
				printf("Enter the right choice! ");
		}
		
	}
	return 0;
}

void push(int y){
	if (top!=19){
		top++;
		stack[top]=y;
	}
	else
		printf("Overflow");
}

void pop(){
	if (top!=-1){
		top--;
	}
	else
		printf("Underflow");
}

void display(){
	int i;
	if (top==-1){
		printf("Underflow");
	}
	else{
		for (i=0;i<=top;i++){
			printf("%d\n",stack[i]);
		}
	}
}

void peek(){
	if (top==-1){
		printf("Underflow");
	}
	else{
		printf("%d", stack[top]);
	}
}






