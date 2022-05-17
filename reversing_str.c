#include <stdio.h>

//prototyping
void push(char);
void pop();

//gloal variables
char stack[20];
char str[20];
top=-1;

int main(){
	printf("Enter a string: ");
	gets(str);
	int i;
	for (i=0;str[i]!='\0';i++){
		push(str[i]);
	}
	pop();
	return 0;
}

void push(char x){
	top++;
	stack[top]=x;
}


void pop(){
	int i;
	for (i=top;i>=0;i--){
		printf("%c",stack[i]);
	}
}
