#include <stdio.h>
int top=-1;
char stack[20];
char str[20];
void push(char);
char pop();
int main(){
	printf("Enter equation");
	gets(str);
	int i,f=1;
	char x;
	for (i=0;str[i]!='\0';i++){
//		printf("%c",str[i]);
		if (str[i]=='(' ||str[i]== '{'||str[i]=='['){
			push(str[i]);
			
		}
		if (str[i]==')'|| str[i]==']'||str[i]=='}'){
			x=pop();
//			printf("pass0");
			if (str[i]==')'&& (x=='['||x=='{')){
				f=0;
//				printf("pass1");
			}
			else if (str[i]==']'&& (x=='('||x=='{')){
				f=0;
//				printf("pass2");
			}
			else if (str[i]=='}'&& (x=='['||x=='(')){
				f=0;
//				printf("pass3");
			}
		}
	}
	if (top>0){
		f=0;
//		printf("pass4");
	}
	if (f==1){
		printf("Balanced");
	}
	else{
		printf("Unbalanced");
	}
	return 0;
}

void push(char x){
	top++;
	stack[top]=x;
//	char y;
//	y=stack[top];
//	printf("%c",y);
//	printf("hi %d",top);
}

char pop(){
	char y;
	y=stack[top];
//	printf("%c",y);
	top--;
//	printf("%dhello",top);
	return y;
	
}
