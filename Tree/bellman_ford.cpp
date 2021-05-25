//shorted path in a graph containing -ve weights
// bellman ford does not work if graph is containing -ve weight cycle
#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
	int v;
	int wt;
	node(int first,int second,int weight){
		u = first;
		v = second;
		wt = weight;
	}
};
int main(){
    int N,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++){
    	int u,v,wt;
    	cin>>u>>v>>wt;
    	edges.push_back(node(u,v,wt));
    }
    int src;
    cin>>src;
    vector<int> dist(N,INT_MAX);
    dist[src] = 0;
    // relaxing n-1 times all the edges
    for(int i=1;i<=N-1;i++){
    	for(auto it:edges){
    		if(dist[u] != INT_MAX && dist[it.u] + it.wt < dist[it.v]){
    			dist[it.v] = dist[it.u] + it.wt; 
    		}
    	}
    }
    // doing the relaxation one more time to check if there is negative cycle or not
    // if any distance changes that means there's a negative cycle
    int flag = 0;
    for(auto it:edges){
    	if(dist[it.u] != INT_MAX && dist[it.u] + it.wt < dist[it.v]){
    		cout<<"Negative Cycle"<<endl;
    		flag = 1;
    		break; 
    	}
    }
	return 0;
}