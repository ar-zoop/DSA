#include <stdio.h>
void push(int i);
void pop();
char stack[20];
char str[20];
int top=-1;
int main(){
	
	int i=0;
	printf("Enter the string: ");
	gets(str);
	while(str[i]!='\0'){
		push(i);
		i++;
	}
	
	for (i=top;i>=0;i--){
		pop();
	}
	return 0;
	
}

void push(int i){
	if (top!=19){
		top++;
		stack[top]=str[i];
	}
}

void pop(){
	if (top!=-1){
		printf("%c",stack[top]);
		top--;
	}
}
