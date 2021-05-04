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
Node* Insert(struct Node* root, int key){
	if(root == NULL){
		root = new Node(key);
		return root;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		else {
			temp->left = new Node(key);
			return root;
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
		else {
			temp->right = new Node(key);
			return root;
		}
	}
	return root;
}
void inorder(struct Node* root){
	if(root == NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt", "r", stdin);
 //        freopen("output1.txt", "w", stdout);
 //    #endif
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
    cout<<"Inorder of BT before inserting: ";
	inorder(root);
	cout<<endl;
	int key = 9;
	root = Insert(root,key);
    cout<<"Inorder of BT after inserting: ";
    inorder(root);
	cout<<endl;
}