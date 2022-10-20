#include <bits/stdc++.h>
using  namespace std;
int main(){
    int i, j, count=10, arr[10]={1,3,5,6,8,1,1,9,0,2}, key;
    for(i=1; i<count; i++){
        key=arr[i];
        j=i-1;
        while(j>=0  && arr[j]<key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(i=0;i<count;i++)
      cout<<arr[i]<<" ";
    return 0;
} 