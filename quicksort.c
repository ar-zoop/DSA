#include <stdio.h>
int partition(int[], int,int);
void quickSort(int[], int,int);
void swap(int *, int*);
int main(void){
//	int arr[7]={10,80,30,90,40,50,70};
	int arr[5]={3,5,2,1,4};
	quickSort(arr,0,4);
	int i;
	for(i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

int partition(int arr[],int start, int end){
	int pivot=arr[end];
	int i=start-1,j;
	for(j=start;j<=end;j++){
		if (arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
//	swap(&arr[i+1],&arr[end]);
	return (i);
}

void quickSort(int arr[],int start, int end){
	if (start<end){
		int pi=partition(arr,start,end);
		quickSort(arr,start,pi-1);
		quickSort(arr,pi+1,end);
	}
}

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
