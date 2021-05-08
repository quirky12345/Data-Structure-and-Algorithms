#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int start = 0,end = 0;
    int max_len = end-start+1;
    int n = s.size();
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)dp[i][i] = true;
    for(int len = 2;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j = i+len-1;
            if(len == 2 && s[i] == s[j]){
                dp[i][j] = true;
                if(len>max_len){
                    start = i;
                    end = j;
                    max_len = 2;
                }
            }
            else if(dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] = true;
                if(len>max_len){
                    max_len = len;
                    start = i;
                    end = j;
                }
            }
        }
    }
    string s1 = "";
    for(int i = start;i<=end;i++)s1+=s[i];
    return s1;
}
int main(){
	string s = "babad";
	//cin>>s;
	cout<<longestPalindrome(s);
	return 0;
}