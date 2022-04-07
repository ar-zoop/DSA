#include <stdio.h>
#define SIZE 20
#define MAX 9
int main(){
	int inp[SIZE]={4,5,6,3,4,6,7,3,1,2,4,6,7,3,1,2,4,6,7,9};
	//initilaising count
	int outp[SIZE],count[MAX]={0},i;
	//defininf count
	for (i=0;i<SIZE;i++){
		count[inp[i]]+=1;
	}
	//modifying count
	for (i=1;i<=MAX;i++){
		count[i]+=count[i-1];
	}
	//defining outp and reducing count
	for(i=0;i<SIZE;i++){
		outp[--count[inp[i]]]=inp[i];
	}
	for (i=0;i<SIZE;i++)
		inp[i]=outp[i];
	for (i=0;i<SIZE;i++)
		printf("%d ",outp[i]);
	return 0;
}
