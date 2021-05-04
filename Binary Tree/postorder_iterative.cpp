#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left = right = NULL;
	}
};
// void postorder(struct Node* root){
// 	if(!root)return;
// 	postorder(root->left);
// 	postorder(root->right);
// 	cout<<root->data<<" ";
// 	return;
// }
void postorder(struct Node* root){
	if(!root)return;
	stack<Node*> s;
	stack<int> out;
	//Node* curr = root;
	s.push(root);
	while(!s.empty()){
		Node* curr = s.top();
		s.pop();
		out.push(curr->data);
		if(curr->left)s.push(curr->left);
		if(curr->right)s.push(curr->right);
	} 
	while(!out.empty()){
	   cout<<out.top()<<" ";
	   out.pop();
	}
	return;
}
int main(){
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    postorder(root);
	return 0;
}