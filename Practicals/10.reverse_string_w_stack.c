#include <stdio.h>

void push(char);
int pop();

char stack[20];
int top=-1;

int main(){
	int i;
	char str[20],x;
	gets(str);
	for (i=0;i<str[i]!='\0';i++)
		push(str[i]);
	while(top>-1){
		x=pop();
		printf("%c",x);
	}	
	return 0;	
}

int pop(){
	return stack[top--];
}

void push(char x){
	if(top!=19)
		stack[++top]=x;
	else
		printf("Overflow");
}
