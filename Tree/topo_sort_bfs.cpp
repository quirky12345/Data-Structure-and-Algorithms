#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	void topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> in_deg(V,0);
	    for(int i=0;i<V;i++)
	    	for(auto it:adj[i])in_deg[it]++;
	    
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    	if(in_deg[i] == 0)q.push(i);
	    
	    int count = 0;
	    vector<int> topo_sort;
	    while(!q.empty()){
	    	int s = q.front();
	    	q.pop();
	    	topo_sort.push_back(s);
	    	for(auto i:adj[s]){
	    		if(--in_deg[i] == 0)q.push(i);
	    	}
	    	count++;
	    }
	    if(count!=V){
	    	cout<<"There exists a cycle in a graph"<<endl;
	    	return;
	    }
	    for(int i=0;i<topo_sort.size();i++)cout<<topo_sort[i]<<" ";
	    cout<<endl;
	    return;
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
        obj.topoSort(N, adj);
    }
    
    return 0;
}  // } Driver Code Ends