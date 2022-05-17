#include <stdio.h>
void push(char ch);
char pop();
void peek();
void display();
int stack[100];
int top=-1,n=100;

int precedance(char operator);

int main()
{
    char infix[100]="a-b*(c/d^e)",x;
//    printf("Enter infix expression = \n");
//    gets(infix);
    push('(');
    int i;
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(' )
        {
            push(infix[i]);
            continue;
        }
        if(infix[i]==')')
        {
            while (stack[top]!='(')
            {
                x=pop();
                printf("%c",x);
            }
            pop();
            continue;
        }
        if(infix[i]!='*' && infix[i]!='/' && infix[i]!='+' && infix[i]!='-')
        {
            printf("%c",infix[i]);
            continue;
        }
        
        else
        {
            if(precedance(infix[i])>precedance(stack[top]) )
            {
                x=infix[i];
                push(x);
            }
            else
            {
                while( (precedance(stack[top]) >= precedance(infix[i])))
                {
                    x=pop();
                    printf("%c",x);
                }
                push(infix[i]);
            }
        }
        
    }
    while (stack[top]!='(')
    {
        x=pop();
        printf("%c",x);
    }

    return 0;
}

int precedance(char operator)
{
    switch (operator)
    {
    
    case '*':
        return 4;
        break;
    
    case '/':
        return 4;
        break;
    
    case '+':
        return 2;
        break;
    
    case '-':
        return 2;
        break;
    
    default:
        return 0;
        break;
    }
}
void push(char ch)
{
    if(top>n-1)
        printf("\nOverflow condition ! Cant insert element.\n");
    else
    {
        top++;
        stack[top]=ch;
    }
}
char pop()
{
    if(top==-1) printf("\nUnderflow Condition!\n");
    else 
    {
        int temp=top;
        top=top-1;
        return stack[temp];
    }
}
