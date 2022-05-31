#include <stdio.h>
int main(){
	int t,m,x,y,a,i,count;
	scanf("%d", &t);
	while(t--){
		int houses[100]={0};
		scanf("%d%d%d", &m,&x,&y);
		count=100;
		while(m--){
			scanf("%d",&a);
			//forward
			
			for (i=a-1;i<(a+(x*y));i++){
			 //   printf("i=%d\n",i);
				if(i==100)
					break;
				else if(houses[i]==0){
					houses[i]=1;
					count--;
				}
			}
			//backward
				for (i=a-1;i>(a-(x*y));i--){
			 //   printf("i=%d\n",i);
				if(i==-1)
					break;
				else if(houses[i]==0){
					houses[i]=1;
					count--;
				}
			}
			if(count==0){
				break;
			}
		}
		
		printf("%d\n",count);
	}
	return 0;
}
