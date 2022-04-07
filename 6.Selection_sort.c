#include <stdio.h>
#define MAX 6
int main(){	
	int arr[MAX]={7,4,2,5,8,3},i,pos,temp,j;
	for(i=0;i<(MAX-1);i++){	
		pos=i;
		for (j=i+1;j<MAX;j++){
			if(arr[pos]>arr[j])
				pos=j;
		
		}
			temp=arr[pos];
			arr[pos]=arr[i];
			arr[i]=temp;
		
	}
	printf("Sorted array is: ");
	for (i=0;i<MAX;i++)
		printf("%d ",arr[i]);
	return 0;
}
