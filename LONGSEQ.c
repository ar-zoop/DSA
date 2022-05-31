#include <stdio.h>
#define MAX 100001
int main(){
	int t,i;
	char arr[MAX];
	scanf("%d",&t);
	while(t--){
		int count_0=0,count_1=0;
		scanf("%s",arr);
		for(i=0;arr[i]!='\0';i++){
			if (arr[i]=='0')
				count_0++;
			else
				count_1++;
		}
		if(count_1==1 || count_0==1)
			printf("Yes\n");
		else
			printf("No\n");	
	}
	
	return 0;
}
