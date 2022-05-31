#include <stdio.h>
void main(){
	int arr[11]={1,5,3,7,9,2,5,7,6,4,3},i,ele,flag=1;
	printf("Enter the number you want to find: ");
	scanf("%d", &ele);
	for (i=0;i<10;i++){
		if (ele==arr[i]){
			printf("Element found at %d", i+1);
			flag=-1;
			break;
		}
		
	}
	if (flag>0){
		printf("Element not found");
	}

}
