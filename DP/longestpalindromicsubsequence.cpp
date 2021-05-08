#include<bits/stdc++.h>
using namespace std;
int longestpalindromic(string s){
	int n = s.size();
	int dp[n][n];
	//subsequence of length 1
	for(int i=0;i<n;i++)dp[i][i]=1;
	//for subsequence of length 2 to n
	for(int len = 2;len<=n;len++){
		//for each length will iterate through i to n - len
		for(int i=0;i<n-len+1;i++){
			//last index of substring of length len
			int j = i + len -1;
			//if length is 2 and first and last index has same alphabet
			if(s[i]==s[j])dp[i][j] = 2;
			//if first and last index has same alphabet and length>2
			//then dp[i][j] = 2(because of first and last index) + dp[i+1][j-1](removed first and last index)
			else if(s[i]==s[j])dp[i][j] = dp[i+1][j-1]+2;
			//else you can include and exclude first and last alphabet
			//and get the maximum
			else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
		}
	}
	return dp[0][n-1];
}
int main(){
	string s;
	cin>>s;
	cout<<longestpalindromic(s);
}