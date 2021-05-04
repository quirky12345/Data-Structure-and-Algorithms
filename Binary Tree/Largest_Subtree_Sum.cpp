#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* right;
	struct Node* left;
	Node(int val){
		data = val;
		right = left = NULL;
	}
};
int findLargestSubtreeSumUtil(Node* root,int& ans){
    if(root==NULL)return 0;
    int sum_here = root->data + findLargestSubtreeSumUtil(root->left, ans) + findLargestSubtreeSumUtil(root->right,ans);
    if(ans<sum_here)ans = sum_here;
    return sum_here;
}
int findLargestSubtreeSum(Node* root){
	if(root==NULL)return 0;
	int ans = INT_MIN;
	findLargestSubtreeSumUtil(root,ans);
	return ans;
}
int main(){
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
  
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
  
    cout << findLargestSubtreeSum(root);
	return 0;
}