#include<bits/stdc++.h>
using namespace std;
int AlternatingaMaxLength(int nums[],int n){
	// initializing two pointers to calculate the size of 
	// longest alternating subsequence
    int inc = 1;
    int dec = 1;
    for(int i=1;i<n;i++){
    	//this is maxima,so we increase inc value from dec(minima)+1
        if(nums[i]>nums[i-1])inc = dec + 1;
        //this is minima,so we increase dec value from inc(maxima)+1
        else if(nums[i]<nums[i-1])dec = inc + 1;
    }
    return max(inc,dec);
}
// Driver Code
int main(){
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++)cin>>nums[i];
	cout<<AlternatingaMaxLength(nums,n);
	return 0;
}