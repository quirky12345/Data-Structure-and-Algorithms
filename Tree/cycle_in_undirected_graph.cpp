#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10005];
bool isCycleUtil(int u,bool visited[],int parent,vector<int> adj[]){
    visited[u] = true;
    for(auto i:adj[u]){
        if(!visited[i]){
            if(isCycleUtil(i,visited,u,adj))return true;
        }
        else if(i != parent)return true;
    }
    return false;
}
bool isCycle(int V, vector<int>adj[])
{
    bool visited[V];
    memset(visited,false,sizeof(visited));
    for(int u = 0;u<V;u++){
        if(!visited[u])
          if(isCycleUtil(u,visited,-1,adj))return true;
    }
    return false;
    // Code here
}
int main(){
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=e;i++){
      int x,y;
      cin>>x>>y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    if(isCycle(v,adj))cout<<"Cycle Found, now ride it";
    else cout<<"No cycle found, now you should buy a new car";
	return 0;
}