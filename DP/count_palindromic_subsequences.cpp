#include<bits/stdc++.h>
using namespace std;
long long int  countPS(string str)
{
   long long int n = str.size();
   //this question's approach will be same as length of longest palindrome
   long long int dp[n][n];
   memset(dp,0,sizeof(dp));
   for(int i=0;i<n;i++)dp[i][i] = 1;
   long long int MOD = 1e9+7;
   //for each length len we will calculate dp[i][j]
   for(int len = 2;len<=n;len++){
       for(int i = 0;i<n-len+1;i++){
       	   //last index of length len
           int j = i+len-1;
           //if first and last index is same then dp[i][j] will contain
           //remove last index or remove first index and add 1
           if(str[i] == str[j])dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1)%MOD;
           //if first and last index is not equal then dp[i][j] will contain
           //remove last index or remove first index but both will contain the 
           //palindromic subsequences of dp[i+1][j-1], so we have to remove that
           else dp[i][j] = (dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%MOD;
           if(dp[i][j]>=MOD)dp[i][j]-=MOD;
           else if(dp[i][j]<0)dp[i][j]+=MOD;
       }
   }
   return dp[0][n-1];
   //Your code here
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
	string s;
	cin>>s;
	cout<<countPS(s);
	return 0;
}