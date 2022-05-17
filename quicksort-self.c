#include <stdio.h>
#define SIZE 10

void quicksort(int [],int, int);
int partition(int[],int,int);
void swapp(int * , int *);

void printArray(int arr[], int size)

{

int i;

for (i=0; i < size; i++)

printf("%d ", arr[i]);


}

int main(){
	int arr[SIZE]={3,4,7,1,2,6,8,9,0,5},lb=0,ub=SIZE-1,i;
	quicksort(arr,lb,ub);
	printArray(arr,SIZE);
	return 0;
}

void quicksort(int a[],int lb, int ub){
	int loc;
	if(lb<ub){
		loc=partition(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}

int partition(int a[], int lb, int ub){
	int pivot, end, start;
	pivot=a[lb];
	start=lb;
	end=ub;
	while(start<end){
		//step 1 : find the number greater than pivot
		while(a[start]<=pivot)
			start++;
		//step 2: fidn the unmber smaller than pivot
		while(a[end]>pivot)
			end--;
		//step 3: swap the numbers
		if(start<end)
			swapp(&a[start],&a[end]);
	}
	//step LAST: bring pivot (a[lb]) to the correct position (a[end])
	swapp(&a[end],&a[lb]); 
	return end;
}


void swapp(int * a, int * b){
	int temp= *a;
	*a=*b;
	*b=temp;
}

