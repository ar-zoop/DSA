#include <stdio.h>
#define MAX 20
int q[20],f=-1,r=-1;

void fenqueue();
void renqueue();
void rdequeue();
void fdequeue();

int main(){
	int ch,x;
	printf("Your choices:\n1)Front insert\n2)Back insert\n3)Front delete\n4)Back delete\n5)Display: ");
	while(1){
		scanf("%d", &ch);
		switch(ch){
			case 1: 
				printf("Enter value: ");
				scanf("%d", &x);
				fenqueue(x);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &x);
				renqueue(x);
				break;
			case 3:			
				fdequeue();
				break;				
			case 4:
				rdequeue();
				break;
			case 5:
				display();
				break;
			default:
				printf("Invalid choice!");
		}
	}
	return 0;
}

void fenqueue(int data){
	if(f==-1){
		f=r=0;
		q[f]=data;
	}
	else if(f==0){
		printf("No space");
	}
	else{
		q[++f]=data;
	}
}

void renqueue(int data){
	if (r==MAX-1)
		printf("Overflow");
	else if(f==-1 && r==-1)
		f=r=0;
	else
		r++;
		
	q[r]=data;
}

void fdequeue(){	
	if(f==-1)
		printf("Underflow");
	else if(r==f)
		r=f=-1;
	else{
		printf("Value dequeued= %d\n",q[f]);
		f++;
	}
}

void rdequeue(){
	if(f==-1)
		printf("Underflow");
	else{
		printf("Value dequeued= %d\n",q[r]);
		r--;
	}
}

void display(){
	int i;
	for (i=f;i<=r;i++)
		printf("%d ",q[i]);
}
