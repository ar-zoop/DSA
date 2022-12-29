#include <bits/stdc++.h>
using  namespace std;

void dfs(int i, vector<int> adj[], int n){
 if(i==n) return;
 for(int j=0; j<adj[i].size(); j++){
     
 }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr [n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    dfs(1, arr, n+1);

    return 0;
} 