#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int rnum;
    char name[30];
}stud;
int main()
{
    stud *p;
    int n,i;
    printf("Enter number of student: ");
    scanf("%d",&n);
    p=(stud*)malloc(n*sizeof(stud));
    for(i=0;i<n;i++)
    {
        printf("\nEnter Roll num and name of the student: ");
        scanf("%d",&(p+i)->rnum);
        fflush(stdin);
        gets((p+i)->name);
    }
    for(i=0;i<n;i++)
    {
        printf("\n------Record of %d student-------\n",i);
for(i=0;i<n;i++)
    {
        printf("\n------Record of %d student-------\n",i+1);
        printf("\nRoll Number: %d",(p+i)->rnum);
        printf("\nName: %s",(p+i)->name);
    }
    free(p);
    return 0;
}
