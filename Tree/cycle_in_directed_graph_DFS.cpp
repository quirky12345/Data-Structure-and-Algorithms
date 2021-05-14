#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool isCyclicDFS(int s,vector<int> adj[],bool vis[],bool dfsvis[]){
        // make both visited and dfsvisited of s as true
        vis[s] = true;
        dfsvis[s] = true;
        for(auto i:adj[s]){
            // if not visited
            if(!vis[i]){
                // if you find a cycle while DFS of i:  then return true;
                if(isCyclicDFS(i,adj,vis,dfsvis))return true;
            }
            // if visited and dfsvisited of i is true
            // i.e. we are still in the recursion of i then it means
            // we found a cycle, so return true 
            else if(dfsvis[i] == true)return true;
        }
        // backtrack and make dfs visited of s as false
        // Note that we are not making visited as false
        dfsvis[s] = false;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
        // initialize two array: visited and dfsvisited
        // visited: for checking it we have traversed a node or not
        // dfsvisited: for checking if we are still in a recursion tree of some node or not
	    bool vis[V],dfsvis[V];
        // initialize both the array as false in the starting
	    memset(vis,false,sizeof(vis));
	    memset(dfsvis,false,sizeof(dfsvis));
        // check for each component of graph if there is cycle of not
        // if there is a cycle: return true
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	          if(isCyclicDFS(i,adj,vis,dfsvis))return true;
	    }
        // else: return false;
	    return false;
	   	// code here
	}
};

// { Driver Code Starts.


int main()
{
    // no. of test cases
    int t;
    cin >> t;
    while(t--)
    {
        // 
    	int V, E;
        cin >> V >> E;
        // initializing the adjacency list
    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }
    return 0;
}

  // } Driver Code Ends