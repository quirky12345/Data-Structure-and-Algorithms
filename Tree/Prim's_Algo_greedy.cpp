#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > g[1005];
int main(){
	int V,E;
	cin>>V>>E;
    for(int i = 0;i<E;i++){
    	int a,b,wt;
    	cin>>a>>b>>wt;
    	g[a].push_back({b,wt});
    	g[b].push_back({a,wt});
    }
    // array to store contructed mst;
    int parent[V];
    // Key values used to pick minimum weight edge in cut 
    int key[V];
    //for checking if the node is included in the mst yet or not.
    bool mstSet[V];
    // Initialize key and mstSet
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false,parent[i] = -1; 

    key[0] = 0;

    for (int count = 0; count < N - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
        // Calculating the first vertices with minm weight
        for (int v = 0; v < N; v++) 
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v;  
                
        mstSet[u] = true; 
        
        for (auto it : g[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}