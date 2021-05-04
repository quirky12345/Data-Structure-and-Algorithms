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
int main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	//cout<<root->left->data<<endl;
	return 0;
}