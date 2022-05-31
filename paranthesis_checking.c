#include<stdio.h>


//prototyping
void push(char);
int pop();

//global variables
char stack[20];
char str[20];
int top=-1;

int main(){
	
	int i,f=1;
	char x;
	printf("enter equation");
	gets(str);
	for (i=0;str[i]!='\0';i++){
		if (str[i]=='('||str[i]=='{'||str[i]=='['){
			push(str[i]);
		}
		else if(str[i]==')'){
			x=pop();
			if (x=='{'||x=='['){
				f=0;
			}
		}
		else if(str[i]==']'){
			x=pop();
			if (x=='{'||x=='('){
				f=0;
			}
		}
		else if(str[i]=='}'){
			x=pop();
			if (x=='('||x=='['){
				f=0;
			}
		}
	}
//checking if balanced or unbalanced	
	if (top>0){
		printf("Unbalanced");
	}
	
	else if (f==1) {
		printf("Balanced");
	}
	else{
		printf("Unbalanced");
	}
	
	return 0;
}

void push(char x){
	if (top!=19){	
		top++;
		stack[top]=x;
	}
	else{
		printf("Overflow");
	}
}

int pop(){
	char x;
	x=stack[top];
	top--;
	return x;
}





