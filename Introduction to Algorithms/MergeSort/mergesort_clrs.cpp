#include<iostream>
#include <climits>
using namespace std;


void merge(int A[], int start, int mid, int end){
    // cout<<"hi";
    int L[mid-start+2];
    int R[end-mid+1];
    for(int i=0; i<(mid-start+1);i++){
        L[i]=A[start+i];
    }
    for(int j=0; j<(end-mid); j++){
        R[j]=A[1+mid+j];
    }
    //Adding sentinel values here. The purpose is: when one of the arrays reaches the end, it does not go over bounds because the other one will always be smaller and it would always go to the else case.
    L[mid-start+1]=INT_MAX;
    R[end-mid]=INT_MAX;
    int i=0, j=0, k=0;
    for(k=start;k<=end;k++ ){
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }
        else{
            A[k]=R[j++];
        }
    }
   
    return;
}
void mergesort(int A[], int start, int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(A,start,mid);
        mergesort(A,mid+1,end);
        merge(A,start,mid,end);
    }
    else return;
}

int main(){
    int A[8]={2,4,1,6,8,5,3,7};
    for(int i=0; i<8;i++){
        cout<<A[i];
    }
    cout<<endl;
    mergesort(A, 0, 7);
    for(int i=0; i<8;i++){
        cout<<A[i];
    }
    return 0;
}