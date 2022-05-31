//this is queue
#include <stdio.h>
#include <stdlib.h>

void enqueue(int);
void dequeue();
void display();
int f=-1,r=-1;
int q[10];

int main(){	
	int x,ele;
	while (1){
		
		printf("choose an option: ");
		printf("1) enqueue\n2) dequeue\n3)display\n4)exit: ");
		scanf("%d", &x);
		switch(x){
			case (1):
				printf("Enter ele: ");
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nBye");
				exit(0);
				break;
			default:
				printf("Enter correct option!");
		}
		
	
	}
return 0;
}

void enqueue(int y){
	if (f==-1){
		r++;
		f++;
		q[r]=y;
		printf("Done\n");
	}
	else if(q[r]==9){
		printf("Overflow\n");
	}
	else{
		r++;
		q[r]=y;
		printf("Done\n");
	}
}

void dequeue(){
	if (f==-1){
		printf("Underflow\n");
	}
	else{
		f++;
		printf("Done\n");
	}
	
}

void display(){
	int i;
		if (f==-1){
		printf("Underflow\n");
	}
	else{
	for(i=f;i<=r;i++){
		printf("%d\n",q[i]);
	}	
}
}
