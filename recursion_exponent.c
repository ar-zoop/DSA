#include <stdio.h>
float power(float, int);
int main(){
	float a=2,c;
	int b=-2;
//	if(b<0)
//		c=1/power(a,b);
//	else
		c=power(a,b);
	printf("%.2f ^ %d = %.2f",a,b,c);
	return 0;
}
float power(float a, int b){
	if (b==0)
		return 1;
	if(b>0)
		return a*power(a,b-1);
	
	return 1 / power(a,-b);
}
