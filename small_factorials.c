#include <stdio.h>
int main(){
	int t,n,i,j;
	scanf("%d",&t);
	for (i=0;i<t;i++){	
		ULLONG_MAX prod=1;	
		scanf("%d",&n);
		for (j=1;j<=n;j++){
			prod=prod*j;
		}
		printf("%d\n",prod);
	}
	return 0;
}
