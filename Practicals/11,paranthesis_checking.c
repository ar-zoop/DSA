#include <stdio.h>
#define MAX 20
void push(char x);
void pop();

char stack[20];
int top=-1;

int main(){
	char str[20]="(())",x;
	int i;
	if (str[0]=='}'||str[0]==']'||str[0]==')')
		printf("Unbalanced");
		
	else{
		for(i=0;str[i]!='\0';i++){
			if (str[i]=='('||str[i]=='['||str[i]=='{')
				push(str[i]);
			else if(str[i]==')'||str[i]=='}'||str[i]==']'){
				if (str[i]==')'){
					while(stack[top]!='('){
						pop();
//						printf("%c",x);
					}
					
				}
				else if (str[i]==']'){
					while(stack[top]!='['){
						pop();
//						printf("%c",x);
					}
				}
				else{
					while(stack[top]!='{'){
						pop();
//						printf("%c",x);
					}
				}
				pop();
				
			}
		}
		if (top!=-1){
			printf("Unbalanaced");
		}
		else{
			printf("Balanced");
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


void pop(){
	stack[top--];
	
}
