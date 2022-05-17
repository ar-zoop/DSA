#include <stdio.h>

int bin();
    
int main(){	
	int arr[1]={1},ele=0,i,low=0,high=0;
	int a;
	printf("Enter the element to find: ");
    scanf("%d", &ele);
    a=bin(arr,low,high,ele);
    if (a==-1)
    	printf("NOT FOUND");
    else
    	printf("FOUND at %d", a+1);
	return 0;
}

int bin(int arr[],int low,int high,int ele){
	if (low>high)
		return -1;
	else{
		int mid=(low+high)/2;
		if(arr[mid]==ele)
			return mid;
		else if(arr[mid]>ele)
			return bin(arr,low,high-1,ele);
		else
			return bin(arr,low+1,high,ele);
	}
	
}
