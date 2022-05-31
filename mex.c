#include <stdio.h>
int main(){
	int t,n,k,ele,flag,i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&k);
		int s[n];
		for (int i=0;i<n;i++)
			scanf("%d",&s[i]);
		ele=0;	
		begin:for (i=0;i<n;i++){
			if (ele==s[i]){				
				flag=1;
				break;				
			}
			flag=0;
		}
		if (flag==1){
			ele++;
			goto begin;
		}
		
		else if(k>0){
			k--;
			ele++;
			goto begin;
		}
		else{
			printf("%d\n",ele);
		}
}
	return 0;
}
