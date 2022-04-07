#include <stdio.h>
#define MAX 5
int main(){
	int arr[MAX],i,pos;
	printf("Enter 5 nos:\n");
	for (i=0;i<MAX;i++)
		scanf("%d",&arr[i]);
	for (i=0;i<MAX;i++)
		printf("%d ",arr[i]);
	printf("\nEnter the element position you want to delete: ")	;
	scanf("%d",&pos);
	for (i=pos-1;i<5;i++){
		arr[i]=arr[i+1];
	}
	for (i=0;i<MAX-1;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
