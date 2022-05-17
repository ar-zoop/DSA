#include <stdio.h>
#include <stdlib.h>

void enqueue(int);
int dequeue();

int a[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
};
int f=-1,r=-1;
int visited[7]={0};
int q[100]={0};

int main(){
    int i=1,node;
	printf("%d ",i);
	visited[i]=1;
	enqueue(i);
    while(f!=-1){
		node= dequeue();
		for (int j=0;j<7;j++){        
			if(a[node][j]==1 && visited[j]==0){
				printf("%d ",j);
				visited[j]=1;
				enqueue(j);
			}
		}
    }
    return 0;
}


void enqueue(int y){
	if (f==-1){
		r++;
		f++;
		q[r]=y;
	}
	else if(q[r]==100){
		printf("Overflow\n");
	}
	else{
		r++;
		q[r]=y;
	}
}

int dequeue(){
	if (f==-1){
		printf("Underflow\n");
	}
	else{
		return q[f++];
	}
	
}