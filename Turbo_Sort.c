#include <stdio.h>
int main(){
	int t,i,temp,j;
	scanf("%d",&t);
	int arr[t];
	for (i=0;i<t;i++){
		scanf("%d",&arr[i]);
	}
//	sorting in ascending order!
	for (i=1;i<t;i++){
		temp=arr[i];
		j=i-1;
		while((j>=0)&&temp<arr[j]){
			arr[j+1]=arr[j];				
			
			j--;
		}
		arr[j+1]=temp;
	}
	for (i=0;i<t;i++){
		printf("%d",arr[i]);
	}
	return 0;
}

