




///////////WRONG
#include <stdio.h>
//#include <ctype.h>
int top =-1;
char stack[50];
int precedence(char);
void push(char);
char pop(); 
int main()
{
	int i;
	char str[20]="x*y/(a*z)+b", x;
	for( i =0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i]))
			printf("%c", str[i]);
		else if(stack[i] == '(')
		{
			push(str[i]);
		}
		else if(stack[i] == ')')
		{
			while(((x=pop())!='('))
				printf("%c", x);
		}
		else
		{
			if(precedence(str[i])<= precedence(stack[top]))
			{
				printf("%c", pop());
				push(str[i]);
			}

		}
		while (top>-1)
		{
			printf("%c", pop);
		}
		
	}
	return 0;
}
int precedence(char symbol)
{
	
	if (symbol == '*' || '/')
		return 2;
	else if (symbol == '+' || '-')
		return 1;
	else
		return 0;
}
void push(char item)
{
	stack[++top] = item;
}
char pop()
{
	return stack[top--];
}
