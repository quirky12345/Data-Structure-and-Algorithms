#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,ll> mp;
ll n;
void lca(ll u,ll v,ll w){
    ll a = u;
    u = min(u,v);
    v = max(a,v);
    while(v>u){
        mp[v] += w;
        v = v/2;
        //cout<<mp[v]<<" "<<v<<endl;
        if(v<u)swap(v,u);
    }
}
ll res(ll u,ll v){
    ll a = u;
    u = min(u,v);
    v = max(a,v);
    ll ans = 0;
    while(v>u){
        if(v!=u)ans+=mp[v];
        v = v/2;
        if(v<u)swap(v,u);
    }
    return ans;
}
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(x==1){
            ll u,v,w;
            cin>>u>>v>>w;
            lca(u,v,w);
        }
        else {
            ll u,v;
            cin>>u>>v;
            cout<<res(u,v)<<endl;
        }
    }
    return 0;
}

 