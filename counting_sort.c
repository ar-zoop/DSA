#include <stdio.h>

int main(){
	int k=9,n=17,i,pos;//here k is the max value	
	int arr[17] ={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
	int count[10]={0};
	int b[17];
	for (i=0;i<n;i++){
	 	  count[arr[i]]+=1;
	 	  
	}

	 
	for (i=1;i<=k;i++){
	 	 count[i]=count[i]+count[i-1];
	}
	 
	for (i=n-1;i>=0;i--){	  	
 		count[arr[i]]-=1;
		pos=count[arr[i]];	
		b[pos]=arr[i];
//		b[--count[arr[i]]]=arr[i];
	}
	  
	for (i=0;i<n;i++){
	  	arr[i]=b[i];
	}
	  
	for (i=0;i<n;i++){
	  	printf("%d ",arr[i] );
	}
	return 0;
}
