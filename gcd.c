#include<stdio.h>
int gcd(int, int);
int main(){
	int t=gcd(7,12);
	printf("%d",t);
	return 0;
}
int gcd(int a, int b){
	if (b>a){
		gcd(b,a);
	}
	else if((a>=b)&& (a%b==0)){
		return b;
	}
	return gcd(b,a%b);
}

