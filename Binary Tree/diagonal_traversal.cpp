#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left = right = NULL;
	}
};
void diagonalprintutil(map<int,vector<int>> &mp,int d,struct Node* root){
	if(root == NULL)return;
	mp[d].push_back(root->data);
	diagonalprintutil(mp,d+1,root->left);
	diagonalprintutil(mp,d,root->right);
	return;
}
void diagonalprint(struct Node* root){
	map< int, vector<int> > mp;
	diagonalprintutil(mp,0,root);
	cout<<"Diagonal Traversal: "<<endl;
	for(auto it: mp){
		vector<int> v = it.second;
		int d = it.first;
		cout<<"Diagonal "<<d<<": ";
		for(auto it: v)cout<<it<<" ";
		cout<<endl;
	}
    return;
}
int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    diagonalprint(root);
   return 0;
}