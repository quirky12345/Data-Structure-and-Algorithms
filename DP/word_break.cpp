//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
    if(A.size() == 0)return 0;
    unordered_map<string,int> mp;
    int n = A.size();
    for(int i=0;i<B.size();i++)mp[B[i]]++;
    bool dp[n+1];
    memset(dp,false,sizeof(dp));
    for(int i=1;i<=n;i++){
        //cout<<A.substr(0,i)<<" "<<mp[A.substr(0,i)]<<endl;
        //cout<<dp[i]<<" "<<endl;
        if(dp[i] == false && mp[A.substr(0,i)]>0)dp[i] = true;
        //cout<<dp[i]<<" "<<endl;
        if(dp[i] == true){
            if(i == n)return 1;
            for(int j = i+1;j<=n;j++){
                //cout<<A.substr(i,j-i)<<endl;
                if(dp[j] == false &&  mp[A.substr(i,j-i)]>0)dp[j] = true;
                if(j == n && dp[j] == true)return 1;
            }
        }
    }
    //cout<<dp[n]<<endl;
    return 0;
    //code here
}