#include<bits/stdc++.h>
using namespace std;
#define MAX 5
vector<vector<int>> adj(5,vector<int> (5,0));

bool isSafe(int row, int col,vector<vector<int>> &m,
                 int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||
                  col == n || visited[row][col]
                           || m[row][col] == 0)
        return false;
 
    return true;
}

// Function to print all the possible
// paths from (0, 0) to (n-1, n-1).
void printPathUtil(int row, int col,vector<vector<int>> &m,
              int n, string& path, vector<string>& possiblePaths, bool visited[][MAX])
{
// This will check the initial point
// (i.e. (0, 0)) to start the paths.
    if (row == -1 || row == n || col == -1
               || col == n || visited[row][col]
                           || m[row][col] == 0)
        return;
 
    // If reach the last cell (n-1, n-1)
    // then store the path and return
    if (row == n - 1 && col == n - 1) {
        possiblePaths.push_back(path);
        return;
    }
 
    // Mark the cell as visited
    visited[row][col] = true;
 
    // Try for all the 4 directions (down, left,
    // right, up) in the given order to get the
    // paths in lexicographical order
 
    // Check if downward move is valid
    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n,path, possiblePaths, visited);
        path.pop_back();
    }
 
    // Check if the left move is valid
    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n,path, possiblePaths, visited);
        path.pop_back();
    }
 
    // Check if the right move is valid
    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n,path, possiblePaths, visited);
        path.pop_back();
    }
 
     // Check if the upper move is valid
    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n,path, possiblePaths, visited);
        path.pop_back();
    }
 
    // Mark the cell as unvisited for
    // other possible paths
    visited[row][col] = false;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));
    // Call the utility function to
    // find the valid paths
    printPathUtil(0, 0, m, n, path,possiblePaths, visited);
    return possiblePaths;
    // Your code goes here
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>adj[i][j];
    findPath(adj, n);
 
    return 0;
}