#include <stdio.h>

void push(char ch);
char pop();

int stack[20], top=-1;

int main(){
	char str[20],x;
	int i;
	printf("Enter eqn: ");
	gets(str);
	for (i=0;str[i]!='\0';i++){
		if (str[i]=='{'||str[i]=='['||str[i]=='('){
			printf("pass1");
			push(str[i]);		
		}
		else if (str[i]=='}'||str[i]==']'||str[i]==')'){
			if ((str[i]=='}' && stack[top]=='{')||(str[i]==']' && stack[top]=='[')||(str[i]==')' && stack[top]=='(')){	
				x=pop();
				printf("%d",x);
			}
			else {
				printf("%c",str[i]);
				push(str[i]);
			}
			
		}
		
	}
	printf("%d",top);
	if (top>=0)
		printf("Unbalanced");
	else {
		printf("Balanced");
	}
	return 0;
}

void push(char str){
	top++;
	printf("in functions top= %d",top);
	stack[top]=str;
	
}

char pop(){
	char x;
	x=stack[top];
	top--;
	return x;
}

