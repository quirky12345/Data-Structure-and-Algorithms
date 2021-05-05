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
        if(n<=9)cout<<n<<endl;
        else {
            ll ans = 0;
            ll p = n;
            ll length = len(n); 
            while(length>1){
                ans+=9;
                p/=10;
                length--;
            }
            //cout<<p<<endl;
            ans+=p-1;
            //cout<<ans<<endl;
            ll final = 0;
            for(ll i=1;i<=len(n);i++)final = (final*10) + p;
            //cout<<final<<endl;
            if(final<=n)ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}