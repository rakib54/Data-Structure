#include <bits/stdc++.h>
using namespace std;
const int N=100;

vector<int>adj[N];
vector<int>visited(N+1,0);

void dfs(int node){
    cout<<node<<" ";
    visited[node] = 1;
    for(int adj_node: adj[node]){
        if(visited[adj_node] == 0){
            dfs(adj_node);
        }
    }

}

int main (){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src =1;
    dfs(src);


    return 0;
}

/*
5 5

1 2
2 4
1 3
4 5
3 5
*/
