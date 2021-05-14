#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteUtil(vector<int> adj[],int s,int color[]){
        queue<int> q;
	    color[s] = 0;
	    q.push(s);
	    while(!q.empty()){
	        int node = q.front();
	        int color_here = color[node];
	        q.pop();
	        for(auto i:adj[node]){
	            if(color[i] == -1){
	                color[i] = 1-color_here;
	                q.push(i);
	            }
	            else if(color[i] == color_here)return false;
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    memset(color,-1,sizeof(color));
	    for (int i = 0; i < V; i++){
            if (color[i] == -1){
               //cout<<i<<endl;
               if (!isBipartiteUtil(adj, i, color))return false;
            }
	    }
 
        return true;
	    // Code here
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends