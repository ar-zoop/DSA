#include <stdio.h>
int main(){
	int arr[6]={3,4,2,5,6,7},ele,flag=0,i;
	printf("Array is: ");
	for (i=0;i<6;i++)
		printf("%d ",arr[i]);
	printf("\Enter the element you want to search: ");
	scanf("%d",&ele);
	for (i=0;i<6;i++){
		if (ele==arr[i])
			{
				flag=1;
				printf("Element found at pos= %d ",i+1);
				break;
			}
			
	}
	if (flag==0)
		printf("Element not found");
	return 0;
}
