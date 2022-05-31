#include <stdio.h>
int main(){
	int arr[7]={7,6,5,4,3,2,1},i,j,temp;
	for (i=0;i<7;i++){
		for (j=0;j<7-i-1;j++){
			if (arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		printf("\n");
	}
	printf("Sorted array is: ");
	for(i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
