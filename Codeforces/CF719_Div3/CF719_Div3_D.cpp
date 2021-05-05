#include<bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define ll long long int
int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll res = 0;
        ll arr[n];
        vector<ll> v;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            v.push_back(arr[i]-i);
        }
        sort(v.begin(),v.end());
        //for(ll i=0;i<n;i++)cout<<v[i]<<" ";
        //cout<<endl;
        ll count = 1;
        for(ll i=1;i<n;i++){
            if(v[i]==v[i-1])count++;
            else {
                res+=(count*(count-1))/2;
                count = 1;
            }
        }
        //cout<<res<<endl;
        //cout<<count<<endl;
        res+=(count*(count-1))/2;
        cout<<res<<endl;
    }
    return 0;
}