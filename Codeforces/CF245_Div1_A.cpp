#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N],res;
int init[N],goal[N];
bool visited[N];
int n;
void dfs(int start,int level,int odd,int even){
     visited[start] = 1;
     if(level & 1){
     	if((odd%2==0 && init[start]!=goal[start]) || (odd%2==1 && init[start] == goal[start]))odd++,res.push_back(start);
     }
     else {
     	if((even%2==0 && init[start]!=goal[start]) || (even%2==1 && init[start] == goal[start]))even++,res.push_back(start);
     }
     for(int x:v[start]){
     	if(visited[x] == false)dfs(x,level+1,odd,even);
     }
}
int main(){
   cin>>n;
   for(int i=2;i<=n;i++){
   	int a,b;
   	cin>>a>>b;
   	v[a].push_back(b);
   	v[b].push_back(a);
   }
   for(int i=1;i<=n;i++)cin>>init[i];
   for(int j=1;j<=n;j++)cin>>goal[i];
   dfs(1,1,0,0);
   cout<<res.size()<<endl;
   for(auto x:res)cout<<x<<endl;
   return 0;
}