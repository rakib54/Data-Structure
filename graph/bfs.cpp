#include <bits/stdc++.h>
using namespace std;
const int N=100;

vector<int>adj[N];
vector<int>visited(N,0);

void bfs(int node){
    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int head = q.front();
        q.pop();
        cout<<head<<" ";
        for(int adj_node:adj[head]){
            if(visited[adj_node] == 0){
                visited[adj_node] = 1;
                q.push(adj_node);
            }
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
    bfs(src);


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

