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
void storenodes(vector<Node*> &nodes,Node* root){
	if(!root)return;
	storenodes(nodes,root->left);
	nodes.push_back(root);
	storenodes(nodes,root->right);
}
Node* ConstructBBST(vector<Node*> &nodes,int start,int end){
	//Node* root;
	if(start>end)return NULL;
    int mid = (start + end)/2;
    Node* root = nodes[mid];
    root->left = ConstructBBST(nodes,start,mid-1);
    root->right = ConstructBBST(nodes,mid+1,end);
	return root;
}
Node* buildtree(Node* root){
	vector<Node*> nodes;
	storenodes(nodes,root);
	return ConstructBBST(nodes,0,nodes.size()-1);
}
void Inorder(Node* root){
	if(!root)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node* root){
	if(!root)return;
	cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
	Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    root = buildtree(root);
    cout<<"Print Inorder after: ";
    Inorder(root);
    cout<<endl;
    cout<<"Print Preorder after: ";
    Preorder(root);
	return 0;
}