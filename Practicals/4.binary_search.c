#include <stdio.h>
#define MAX 10
int main(){
	int arr[MAX]={1,2,3,4,5,6,7,9,10,11},low=0,high=MAX,mid,ele,i;
	for(i=0;i<MAX;i++)
		printf("%d ",arr[i]);
	printf("\nEnter element to search: ");
	scanf("%d", &ele);
	while(low<high){
		mid=(low+high)/2;
		if(ele==arr[mid]){
			printf("Element found at position= %d ",mid);
			break;
		}
		else if(ele>arr[mid]){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(low>=high)
		printf("Element not found");
	return 0;
}
