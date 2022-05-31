#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
void display();
int arr[10];
int top=-1;

int main()
{
    int ch;
    while(1)
    {
        printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n5: Exit : ");
        scanf("%d",&ch);
        switch(ch)
        {
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
            	exit(0);
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
void push()
{	
	if (top!=14){
	    printf("Enter a number you want to push:");
	    top++;
	    scanf("%d",&arr[top]);   
	}
	else{
		printf("Overflow");
	}
}
void pop()
{
    if (top!=-1)
    	top--;
    else
    	printf("Underflow");
	
}
void peek()
{	
	if (top!=-1)
    	printf("%d",arr[top]);
    else
    	printf("Underflow");
}
void display()
{
 	int i;
 	if (top!=-1){
		for(i=0;i<=top;i++){
		 	printf("%d ",arr[i]);
		} 
	}
	else{
		printf("Underflow");
	}
}
