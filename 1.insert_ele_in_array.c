#include <stdio.h>
#define MAX 6
int main(){
	int arr[MAX],i,pos,ele;
	printf("Enter 5 nos: ");
	for (i=0;i<MAX-1;i++)
		scanf("%d",&arr[i]);
	for (i=0;i<MAX-1;i++)
		printf("%d ",arr[i]);
	printf("\nEnter the position where you want to add an elelemt: ")	;
	scanf("%d",&pos);
	printf("\nEnter element: ");
	scanf("%d",&ele);
	for (i=MAX-1;i>=pos;i--){
		arr[i]=arr[i-1];
	}
	arr[pos-1]=ele;
	for (i=0;i<6;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
