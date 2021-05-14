#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Approach is to find the topological sort using kahn's algo
// If the topo sort doesn't exist then there will be a cycle present in the 
// directed graph
class Solution
{
	public:
	bool topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> in_deg(V,0);
	    for(int i=0;i<V;i++)
	    	for(auto it:adj[i])in_deg[it]++;
	    
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    	if(in_deg[i] == 0)q.push(i);
	    
	    int count = 0;
	    while(!q.empty()){
	    	int s = q.front();
	    	q.pop();
	    	count++;
	    	for(auto i:adj[s]){
	    		if(--in_deg[i] == 0)q.push(i);
	    	}
	    }
	    // as we know that topo sort is just a linear ordering of vertices
	    // so total node should be V when queue gets empty
	    if(count!=V)return true;
	    else return false;
	    // code here
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        if(obj.topoSort(N, adj))cout<<"There is a cycle"<<endl;
        else cout<<"There's no cycle bro"<<endl;
    }
    
    return 0;
}  // } Driver Code Ends