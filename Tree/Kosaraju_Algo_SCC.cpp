#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 1e5 + 5;
// directed graph
vector<ll> g[N],gTrans[N];
stack<ll> topo_sort;
bool visited[N];
ll V,E;
void dfs(ll s,ll par){
    if(visited[s] == true)return;
    visited[s] = true;
	for(auto it:g[s]){
		if(it == par)continue;
		if(!visited[it])dfs(it, s);
	}
	//cout<<s<<endl;
	topo_sort.push(s);
}
void dfs_scc(ll s){
    visited[s] = true;
    cout<<s<<" ";
	for(auto it:gTrans[s]){
		if(!visited[it])dfs_scc(it);
	}
}
int main(){
    cin>>V>>E;
    for(ll i = 0;i < E;i++){
    	ll u,v;
    	cin>>u>>v;
    	g[u].push_back(v);
    	gTrans[v].push_back(u);
    }
    dfs(1,0);
    memset(visited,false,sizeof(visited));
    while(!topo_sort.empty()){
    	ll node = topo_sort.top();
    	topo_sort.pop();
    	if(visited[node] == true)continue;
    	dfs_scc(node);
    	cout<<endl;
    }
	return 0;
}