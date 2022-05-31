//structure using malloc
#include <stdio.h>

typedef struct student{
	int rnum;
	char name[30];
}std;

int main(){
	std *p;
	int n,i;
	printf("Enter how many blocks do u need: ");
	scanf("%d",&n);
	p=(std*)malloc(n*sizeof(std));
		
	
	for (i=0;i<n;i++){
		printf("Enter roll number and name: ");
		scanf("%d",&(p+i)->rnum );
		fflush(stdin);
		gets((p+i)->name);
	}
	for (i=0;i<n;i++){
		printf("roll number and name: ");
		printf("%d\n",(p+i)->rnum );
		
		puts((p+i)->name);
	}
	free(p);
	return 0;
}
