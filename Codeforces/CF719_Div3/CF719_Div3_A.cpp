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
        int n;
        cin>>n;
        bool check = false;
        string s;
        cin>>s;
        int arr[26] = {0};
        for(int i=0;i<n;i++){
            int a = (int)(s[i]-'A');
            if(arr[a]==0){
                arr[a]++;
            }
            else {
                if(s[i-1] == s[i])arr[a]++;
                else {
                    check = true;
                    break;
                }
            }
        }
        if(check)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}