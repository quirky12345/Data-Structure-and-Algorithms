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
// void inorder(struct Node* root){
// 	if(!root)return;
// 	inorder(root->left);
// 	cout<<root->data<<" ";
// 	inorder(root->right);
// 	return;
// }
void inorder(struct Node* root){
	if(!root)return;
	stack<Node*> s;
	Node* curr = root;
	while(curr!= NULL || !s.empty()){
		if(curr!=NULL){
			s.push(curr);
			curr = curr->left;
		}
		else {
			curr = s.top();
			s.pop();
			cout<<curr->data<<" ";
			curr = curr->right;
		}
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
    inorder(root);
	return 0;
}