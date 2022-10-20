#include <iostream>
using namespace std;

void merge(int left[], int right[], int arr[], int l, int r){
    int i=0, j=0, k=0;
    while(i<l && j<r){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    /*
    if(i<l){
        
        for(int m=i;m<l;m++){
            arr[k++]=left[m];
        }
    }
    else if(j<r){
        for(int m=j;m<r;m++){
            arr[k++]=right[m];
        }
    }
    */
    
    while(i < l) arr[k++] = left[i++];
	while(j < r) arr[k++] = right[j++];
    return;
    
}

void mergesort(int arr[], int n){
    if(n<2) return;
    int mid=n/2;
    int left[mid];
    int right[n-mid];   
    for(int i=0;i<mid; i++){
        left[i]=arr[i];
    }
    for(int i=mid; i<n;i++){
        right[i-mid]=arr[i];
    }
    mergesort(left, mid);
    mergesort(right, n-mid );
    merge(left, right, arr, mid, n-mid);
}

int main(){
    int arr[5]={5,2,3,4,1};
    mergesort(arr, 5);
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    return 0;
}

