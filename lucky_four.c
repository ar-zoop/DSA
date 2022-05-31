#include <stdio.h>
int main(){
	int t,n,i,count,r;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d",&n);
		count=0;
		while(n>0){
			r=n%10;
			if (r==4){
				count++;
			}
			n=n/10;
		}
		printf("%d",count);
	}
	return 0;
}
