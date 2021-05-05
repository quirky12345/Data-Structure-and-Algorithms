#include<bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define ll long long int
ll len(ll d){
    ll length = 0;
    while(d>0){
        length++;
        d/=10;
    }
    return length;
}
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
        int n;
        cin>>n;
        if(n == 1)cout<<1<<endl;
        else if(n == 2)cout<<-1<<endl;
        else {
            ll final = n*n;
            ll start = 1;
            for(ll i = 1;i<=n;i++){
              for(ll j = 1;j<=n;j++){
                 if(start>final)start = 2;
                 cout<<start<<" ";
                 start+=2;
              }
              cout<<endl;
            }
        }
    }
    return 0;
}