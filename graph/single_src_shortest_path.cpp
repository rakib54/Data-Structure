#include <bits/stdc++.h>
using namespace std;
const int N=100;

vector<int>graph[N];
vector<int>visited(N,0);
int level[N];

void Node_level(int src){
  queue<int> q;
  q.push(src);
  visited[src]= 1;
  level[src]= 0;

  while(!q.empty()){
    int head = q.front();
    q.pop();
    for(int node:graph[head]){
      if(visited[node] == 0){
        visited[node] = 1;
        level[node] = level[head]+1;
        q.push(node);
      }
    }
  }

}
int main(){
  int n,e;
  cin>>n>>e;
  for(int i=0;i<e;i++){
    int u,v;cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int srcNode = 0;
  Node_level(srcNode);

  for(int i=0;i<n;i++){
    cout<<"Node: "<<i<<"-> Level: "<<level[i]<<endl;
  }
}

/*
5 5

0 1
0 2
1 3
3 4
2 4
*/