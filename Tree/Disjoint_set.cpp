#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
// using rank array for union by rank
int rank[N];
int n;
void makeSet(){
	for(int i = 1;i<=n;i++){
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

void main(){
	makeSet();
	// union operations
	int m;
	while(m--){
		int u,v;
		union(u,v);
	}

	// if 2 and 3 belong to the same component or not
	if(findPar(2) != findPar(3))cout<<"differen component"<<endl;
	else cout<<"Same component"<<endl; 
}