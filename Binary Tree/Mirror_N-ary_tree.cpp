#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        stack<int> v1[n+1];
        queue<int> v2[n+1];
        for(int i=0;i<(2*e);i+=2){
            int x = A[i];
            int y = A[i+1];
            v1[x].push(y);
        }
        for(int i=0;i<(2*e);i+=2){
            int x = B[i];
            int y = B[i+1];
            v2[x].push(y);
        }
        bool flag;
        for (int i = 1; i <= n; i++) {
            stack<int>& s = v1[i];
            queue<int>& q = v2[i];
            flag = true;
            while (!s.empty() and !q.empty()) {
                if (s.top() != q.front()) {
                    flag = false;
                    break;
                }
                s.pop();
                q.pop();
            }
            if (flag == false)
                break;
        }
        if(flag)return 1;
        else return 0;
        // code here
    }
};

int main(){
	// ios::sync_with_stdio(0), cin.tie(0);
 //    #ifndef ONLINE_JUDGE
 //        freopen("input.txt", "r", stdin);
 //        freopen("output1.txt", "w", stdout);
 //    #endif
	int n = 8,e = 7;
	//cin>>n>>e;
	int A[2*e] = {1,2,2,3,3,4,3,7,3,8,4,5,5,6};
	int B[2*e] = {1,2,2,3,3,8,3,7,3,4,4,5,5,6};
	for(int i=0;i<2*e;i++)cin>>A[i];
	for(int i=0;i<2*e;i++)cin>>B[i];
	Solution Ob;
    cout<<Ob.checkMirrorTree(n,e,A,B)<<endl;
}