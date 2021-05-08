#include<bits/stdc++.h>
using namespace std;
bool equalPartition(int n, int arr[])
{
    int sum = 0;
    for(int i=0;i<n;i++)sum+=arr[i];
    //if sum is not even the equal partition is not possible
    if(sum%2!=0)return false;
    //dp will be have rows 0 to sum/2(because we are looking for subset whose sum is sum/2)
    //if we get that subset this means another subset will be of the same sum.
    bool dp[(sum/2)+1][n+1];
    // base conditions
    for(int i=0;i<=n;i++)dp[0][i]=true;
    for(int i=1;i<=sum/2;i++)dp[i][0]=false;
    //for each sum we iterate the array
    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
        	// including the last element
            dp[i][j] = dp[i][j-1];
            // if sum value is greater that curr value of element in array
            if(i>=arr[j-1]){
            	// we will take OR with dp[current_sum - element in array][excluding this element]
                dp[i][j] = dp[i][j] || dp[i-arr[j-1]][j-1];
            }
        }
    }
    //Acutally we are following two conditions
    //1. including the last element i.e. dp[i][j] = dp[i][j-1](we are keeping the same sum so this means the element is included)
    //2. excluding the last element i.e. dp[i][j] |= dp[i-arr[j-1]][j-1](we are excluding the sum of the element of array of the 
    //current position this means we have excluded this element)
    return dp[sum/2][n];
    // code here
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	if(equalPartition(n,arr))cout<<"YES";
    else cout<<"NO";
	return 0;
}