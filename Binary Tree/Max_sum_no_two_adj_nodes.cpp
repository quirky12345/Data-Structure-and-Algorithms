#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* right;
	struct Node* left;
	Node(int val){
		data = val;
		left = right = NULL;
	}
};
unordered_map<Node*,int> dp;
int func(Node* root){
	if(!root)return 0;
	if(dp[root])return dp[root];

	int inc = root->data;
	if(root->left){
		inc+= func(root->left->right);
		inc+= func(root->left->left);
	}
	if(root->right){
		inc+= func(root->right->left);
		inc+= func(root->right->right);
	}

	int exc = func(root->left) + func(root->right);

	dp[root] = max(inc,exc);

	return dp[root];
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);
	cout<<func(root);
	return 0;
}