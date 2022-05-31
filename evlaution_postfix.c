#include<stdio.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char e[20];
    int n1,n2,n3,num,i,cat;
    printf("Enter the expression :: ");
    scanf("%s",e);
   
    for (i=0;e[i]!='\0';i++)
    
    {
        if(isdigit(e[i]))
        {
        	cat=e[i]-48;
            printf("%d\n",sizeof(cat));
            push(cat);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(e[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
    }
    printf("\nThe result of expression  =  %d\n\n",pop());
    return 0;
}


