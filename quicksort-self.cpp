#include <stdio.h>
#include <>
#define SIZE 10

int quicksort(int [],int, int);
int partition(int[],int,int);
void swapp(int & , int &);

int main(){
	int arr[SIZE]={3,4,7,1,2,6,8,9,0,5},lb=0,ub=SIZE-1,i;
	quicksort(arr,lb,ub);
	for (i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

int quicksort(int a[],int lb, int ub){
	int loc;
	if(lb<ub){
		loc=partition(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}

int partition(int a[], int lb, int ub){
	int pivot, end, start;
	pivot=a[ub];
	start=lb;
	end=ub;
	while(start<end){
		//step 1 : find the number greater than pivot
		while(start<end)
			start++;
		//step 2: fidn the unmber smaller than pivot
		while(start<end)
			end--;
		//step 3: swap the numbers
		if(start<end)
			swapp(a[start],a[end]);
	}
	//step LAST: bring pivot (a[ub]) to the correct position (a[end])
	swapp(a[end],a[ub]); 
	return end;
}


void swapp(int & a, int & b){
	int temp=a;
	a=b;
	b=temp;
}

