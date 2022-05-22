#include <bits/stdc++.h>
using namespace std;
#define INF 999
int V,src;
int cost[100][100];//adjacency matrix of the graph and its weights
int dist[8];
bool visited[100]; 
int parent[100];

void init(){
    for (int i=0;i<V;i++){
        parent[i]=i;
        dist[i]=INF;
    }
}

int getNearest(){
    int minValue=INF;
    int minNode=0;
    for (int i=0;i<V;i++){
        if (dist[i]<minValue && !visited[i]){
            minValue=dist[i];
            minNode=i;
        }
    }
    return minNode;
}

void dijkstras(){
    int nearest;
    for (int i=0;i<V-1;i++){
        nearest=getNearest();
        visited[nearest]=true;
    }
    for (int adj=0;adj<V;adj++){
        if(cost[nearest][adj]!=INF && 
        dist[adj]>dist[nearest]+cost[nearest][adj]){
            dist[adj]=dist[nearest]+cost[nearest][adj];
            parent[adj]=nearest;
        }
    }
}

void display(){
    cout<<"Node:\t\t\tCost:\t\t\tPath:";
    for (int i=0;i<V;i++){
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" ";
        cout<<i<<" ";
        int parNode=parent[i];
        // while(parNode!=src){
        //     cout<<"<-"<<parNode<<" ";
        //     parNode=parent[parNode];
        // }
        cout<<endl;
    }
}

int main(){

     cin>>V;
     for (int i=0;i<V;i++){
         for (int j=0;j<V;j++){
             cin>>cost[i][j];
         }
     }
     cin>>src;
     dist[src]=0;
     init();
     dijkstras();
     display();
    return 0;
}
