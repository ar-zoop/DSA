#include <stdio.h>
#define MAX 7
int main(){
	int arr[MAX]={3,1,4,8,6,5,4},i,j,ele;
	for (i=1;i<MAX;i++){
		ele=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>ele){
			arr[j+1]=arr[j];//shifting to right
			j--;
		}
		arr[j+1]=ele;
	}
	for (i=0;i<MAX;i++)
		printf("%d ",arr[i]);
	return 0;
}
