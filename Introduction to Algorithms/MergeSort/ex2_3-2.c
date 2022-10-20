#include <stdio.h>
void merge_sort(int[],int,int);
void merge(int[],int,int,int);

int main(){
	int i;
	int arr[10]={5,2,7,3,9,1,4,8,6,0};
	printf("Before sorting:\n");
	for (i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	int p=0, r=9;
	merge_sort(arr,p,r);
	printf("\nAfter sorting:\n");
	for (i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

void merge_sort(int arr[],int p, int r){
	int q;
	if (p<r){		
		q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
//		printf("\n after merge_ort p=%d, r=%d\n",p,r);
		merge(arr,p,q,r);
	
	}
}

void merge(int *arr, int p, int q, int r){
	int n1=q-p+1 ,n2=r-q,i,j, k;
	int B[n1+1], C[n2+1];//set B[n1+1] and C[n2+1] if adding sentinel at the end
	
	//copy arr[p,q] into B and arr[q+1,r] into C
	for (i=0;i<n1;i++){
		B[i]=arr[i+p];
	}
	for (j=0;j<n2;j++){
		C[j]=arr[j+q+1];
	}
	
	
	//sentinel (Optional): 
	B[n1]=99999,C[n2]=99999;
	
	i=0, j=0;
	printf("p=%d, r=%d\n",p,r);
	for (k=p;k<=r;k++){
		if (B[i]<=C[j]){
			arr[k]=B[i];
			i++;
		}
		else{
			arr[k]=C[j];
			j++;
		}
	}
//	while (i < n1) {
//        arr[k] = B[i];
//        i++;
//        k++;
//    }
//    while (j < n2) {
//        arr[k] = C[j];
//        j++;
//        k++;
//    }
}
