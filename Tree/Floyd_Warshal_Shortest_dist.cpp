//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int V = matrix.size();
	    //cout<<V<<endl;
	    int k,i,j;
	    for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if(matrix[i][j] == -1)
					matrix[i][j] = INT_MAX;
			}
		}
	    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (matrix[i][j] > (matrix[i][k] + matrix[k][j]) && (matrix[k][j] != INT_MAX
                        && matrix[i][k] != INT_MAX))
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
        return;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends