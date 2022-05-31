#include <stdio.h>
#include <stdlib.h>
int f = -1, r = -1;
int queue[30];
void enqueue();
void dequeue();
void display();
int main()
{
    int ch;
    while (1)
    {
        printf("Enter the operation you wish to perform\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
            
        case 4:
        	exit(0);
        	
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
void enqueue()
{
    if (r == 29)
    {
        printf("Overflow\n");
    }
    else
    {
        if (f == -1)
        {
            f++, r++;
            printf("Enter the number to enqueue\n");
            scanf("%d", &queue[f]);
        }
        else
        {
            r++;
            printf("Enter the number to enqueue\n");
            scanf("%d", &queue[r]);
        }
    }
}
void dequeue()
{
    if (f == -1)
        printf("Underflow\n");
    else
    {
        printf("%d will be dequeued\n", queue[f]);
        f++;
    }
    if (f > r)
    {
        f = -1, r = -1;
    }
}
void display()
{
	int i;
    if (f == -1)
        printf("Underflow\n");
    else
    {
        printf("The elements in the queue are\n");
        for (i = f; i <= r; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
