#include<bits/stdc++.h>
using namespace std;
//youtube link: https://www.youtube.com/watch?v=ZWd1SbJeBV0
//time: 25 mins
const int N = 5005;
vector<int> v[N];
int n;
int local[N],possible[N];
int dfs(int start,int parent){
	int nodes = 1;
	vector<int> sizes;
	for(int i=0;i<v[start].size();i++){
		if(v[start][i]==parent)continue;
		int temp =dfs(v[start][i],start);
		nodes+=temp;
		sizes.push_back(temp);
	}
	if(!sizes.empty()){
		if(parent!=0){
			sizes.push_back(n-nodes);
		}
        local[0] = 1;
        for(int i=1;i<=n;i++)local[i]=0;
        for(int x:sizes){
        	for(int i = n-x;i>=0;i--){
        		if(local[i]==1)local[x+i] = 1,possible[x+i]= 1;
        	}
        }
	}
	return nodes;
}
int main(){
	cin>>n;
    for(int i=2;i<=n;i++){
    	int x,y;
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
    }
    dfs(1,0);
    vector<int> ans;
	for(int i=1;i<=n-2;i++){
		if(possible[i])ans.push_back(i); 
	}
	cout<<ans.size()<<endl;
	for(int i:ans)cout<<i<<" "<<n-i-1<<endl;
	return 0;
}