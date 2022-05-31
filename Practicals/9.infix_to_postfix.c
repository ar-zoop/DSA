#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void push(char);
char pop();
int priority(char);

char stack[MAX];
int top=-1;

int main(){
	int i,a,j,b;
	char str[MAX]="k+l-m*n+(o^p)*w/u/v*t+q",x;
	printf("In order equation is: ");
	puts(str);
	for (i=0;str[i]!='\0';i++){
		
		if (str[i]=='('||str[i]=='['||str[i]=='{')
			push(str[i]);
		
		else if(str[i]=='^'||str[i]=='*'||str[i]=='/'||str[i]=='%'||str[i]=='+'||str[i]=='-'){
			if(top==-1){
				push(str[i]);
			}
			else{
				a=priority(str[i]);
				b=priority(stack[top]);
				if (a>b){
					push(str[i]);
				}
				else{
					while(priority(stack[top])>=a){
						x=pop();
						printf("%c",x);
					}
					push(str[i]);
				}
			}
		}
		
		else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			if (str[i]==')'){
				while(stack[top]!='('){
					x=pop();
					printf("%c",x);
				}
				
			}
			else if (str[i]==']'){
				while(stack[top]!='['){
					x=pop();
					printf("%c",x);
				}
			}
			else{
				while(stack[top]!='{'){
					x=pop();
					printf("%c",x);
				}
			}
			pop();
			
		}
		
		else{
			printf("%c",str[i]);
		}
		
	}
	if (top>0){
		while(top>=0){
			x=pop();
			printf("%c",x);
			top--;	
		}		
	}
	
	return 0;
}

void push(char x){
	if (top==MAX-1)
		printf("Overflow\n");
	else
		stack[++top]=x;
}


char pop(){
	return stack[top--];
	
}

int priority(char x){
	if (x=='^')
		return 4;
	else if(x=='*'||x=='/'||x=='%')
		return 3;
	else if (x=='+'||x=='-')
		return 2;
	else
		return 1;
}
