#include <stdio.h>
#define MAX 100000
int main(){
	int t,n,doll;
	scanf("%d",&t);
	while(t--){
		int count[MAX]={-1};
		scanf("%d",&n);
		while(n--){
			scanf("%d", &doll);
			count[doll]++;
		}
		for (int i=0;i<MAX;i++){
			if (count[i]%2!=0){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
