#include<stdio.h>

int reverse(int);

int a[4]={1,2,3,4};
int n=4;
int main(){
	int i,m;

	m=reverse(0);
	for(i=0;i<4;i++){
		
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

int reverse(int i){
	int temp;
	if(i==(n/2))
		
		return 0;
		
	temp=a[i];
	a[i]=a[n-i-1];
	a[n-i-1]=temp;
	
	reverse(++i); 
	

}
