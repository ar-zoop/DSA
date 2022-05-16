#include <stdio.h>
#include <stdlib.h>

int a[3][3]={
    {0,1,1},
    {1,0,1},
    {1,1,0}
};

int visited[3]={0};

void dfs(int);

int main(){
    dfs(0);
    return 0;
}

void dfs(int i){
    printf("%d ",i);
    visited[i]=1;
    for (int j=0;j<3;j++){        
        if(a[i][j]==1 && visited[j]!=1){
            dfs(j);
        }
    }
}