#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005];
bool check = false;
bool visited[100005];
void dfs(int start,int parent){
	//if(visited[start] == true)return;
	visited[start] = true;
	for(int i=0;i<v[start].size();i++){
		if(v[start][i] == parent)continue;
		if(visited[v[start][i]]==true){
			check = true;
			return;
		}
		else dfs(v[start][i],start);
	}
	return;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int e;
    cin>>e;
    for(int i=1;i<=e;i++){
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
    	if(v[i].size()==0){
    		cout<<"Graph is not tree";
    		return 0;
    	}
    }
    dfs(1,0);
    //cout<<1<<endl;
    if(check)cout<<"Graph is not tree";
    else cout<<"Graph is tree";
	return 0;
}