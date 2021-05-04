#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
// The idea behind this approach is: find the deepest node using dfs from the node 1 and call it x.
// then again run the dfs from node x to find the deepest node and it will surely be at the max distance which
// will be termed as the diameter of the tree.
vecto<int> v[1000006];
bool visited[1000006];
int x;
void dfs(int start,int parent,int count,int &maxcount){
	if(visited[start])return;
	count++;
	visited[start] = true;
	for(int i=0;i<v[start].size();i++){
       int a = v[start][i];
       if(a == parent)continue;
       if(count>=maxcount){
       	  maxcount = count;
       	  x = a;
       }
       dfs(a,start,count,maxcount);
	}
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int maxcount = INT_MIN;
    for(int i=1;i<=n;i++)visited[i]=false;
    dfs(1,0,0,maxcount);
    for(int i=1;i<=n;i++)visited[i]=false;
    dfs(x,0,0,maxcount);
    cout<<maxcount<<endl;
	return 0;
}