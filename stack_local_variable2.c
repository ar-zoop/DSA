#include <stdio.h>
#include <stdlib.h>

//prototyping
int push(int[],int);
int pop(int);
void peek(int[],int);
void display(int[], int);

int main(){
	int x;
	int stack[20];
	int top=-1;
	while(1){
		printf("Enter the choice:\n");
		printf("1) Push\n2) Pop\n3) Display\n4) Peek\n5) Exit: ");
		scanf("%d",&x);
		
		switch(x){
			case (1):
				top=push(stack,top);
				break;
				
			case (2):
				top=pop( top);
				
				break;
				
			case(3):
				display( stack, top);
				break;
			
			case(4):
				peek(stack,top);
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

int push(int stack[],int top){
	int x;
	if (top!=19){
		
		printf("Enter ele: ");
		scanf("%d",&x);
		top++;
		stack[top]=x;
		
	}
	else	{
		printf("Overflow");
		
	}
	return top;
}

int pop(int top){
	if (top==-1){
		printf("Underflow");
	}
	else{
		top--;
		
	}
	return top;
}

void peek(int stack[],int top){
	if (top==-1){
		printf("Underflow");
	}
	else{
		printf("%d",stack[top]);
		
	}

}

void display(int stack[], int top){
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
