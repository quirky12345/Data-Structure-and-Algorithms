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
void Inordertraversal(Node* root,vector<int> &arr){
    if(!root)return;
    Inordertraversal(root->left,arr);
    arr.push_back(root->data);
    Inordertraversal(root->right,arr);
}
void arrayToBST(vector<int> arr, struct Node* root, int* index_ptr){
	// Base Case
	if (root == NULL)
		return;
	arrayToBST(arr, root->left, index_ptr);
	root->data = arr[*index_ptr];
	(*index_ptr)++;
	arrayToBST(arr, root->right, index_ptr);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> arr;
    Inordertraversal(root,arr);
    sort(arr.begin(),arr.end());
    int i = 0;
    arrayToBST(arr, root, &i);
    return root;
    //Your code goes here
}
void Inorder(Node* root){
	if(!root)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main(){
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	cout<<"Inorder Traversal before: ";
	Inorder(root);
	cout<<endl;
    root = binaryTreeToBST(root);
    cout<<"Inorder Traversal after: ";
    Inorder(root);
	return 0;
}