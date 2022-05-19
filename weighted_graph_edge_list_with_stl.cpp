#include <bits/stdc++.h>
using namespace std;

void addEdge(vector <pair<int, int> >adj[], int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void printGraph(vector<pair<int,int> >  adj[], int V){
    for (int i=0;i<V;i++){
        int v,w;
        
        for (auto x = adj[i].begin(); x!=adj[i].end(); x++){
             v = x->first;
             w = x->second;
             cout<<i<<" and "<<v<<" weight= "<<w <<endl;
        }
            
        cout<<endl;
    }
}

int main(){
    int V=5;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    return 0;
}