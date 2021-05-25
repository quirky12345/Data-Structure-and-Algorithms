#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
// using rank array for union by rank
int rank[N];
int V,E;
struct Node{
	int u;
	int v;
	int wt;
	Node(int first,int second,int weight){
		u = first;
		v = second;
		wt = weight;
	}
};
void makeSet(){
	for(int i = 0;i<=V;i++){
		parent[i] = i;
		rank[i] = 0;
	}
}
int findPar(int node){
	if(parent[node] = node)return node;
	// below line is used for path compression
	return parent[node] = findPar(parent[node]);
}

void union(int u,int v){
	u = findPar(u);
	v = findPar(v);
    // rank will increase only when rank of both u and v are same
    // if rank is not same then attach minimum rank guy to maximum rank guy
    if(rank[u] < rank[v])parent[u] = v;
    else if(rank[v] < rank[u])parent[v] = u;
    else parent[v] = u,rank[u]++;
}
void comp(Node a,Node b){
	return a.wt < b.wt;
}
vector<Node> edges[N];
int main(){
    cin>>V>>E;
    for(int i=0;i<E;i++){
    	int u,v,wt;
    	cin>>u>>v>>wt;
    	edges.push_back(Node(u,v,wt));
    }
    sort(edges.begin(),edges.end(),comp);
    makeSet();
    int cost = 0;
    vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        union(it.u, it.v); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}