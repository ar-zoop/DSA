#include <stdio.h>
int main(){
	int t,n,i,temp,j, min, max,diff;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		int a[n];
		for (i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		max=a[0],min=a[0];
	 	for (i=0;i<n;i++){
	    	if (a[i]>max){
	    		max=a[i];
			}
			if (a[i]<min){
				min=a[i];
			}
	  	}
	  	diff=max-min;
	   
		printf("%d\n", diff);
		
	   
	}
	return 0;
}
