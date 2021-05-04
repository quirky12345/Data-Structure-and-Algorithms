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
Node* ConstructTreeUtil(int pre[],int size,int* index_now,int key,int min,int max){
	if(*index_now>=size)return NULL;
	Node* root = NULL;
	if(key>min && key<max){
		root = new Node(key);
        *index_now = *index_now + 1;
        if(*index_now < size){
        	root->left = ConstructTreeUtil(pre,size,index_now,pre[*index_now],min,key);
        }
        if(*index_now < size){
        	root->right = ConstructTreeUtil(pre,size,index_now,pre[*index_now],key,max);
        }
	}
	return root;
}
Node* ConstructTree(int pre[],int size){
	int index_now = 0;
	return ConstructTreeUtil(pre,size,&index_now,pre[0],INT_MIN,INT_MAX);
}
void Inorder(Node* root){
	if(!root)return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
	return;
}
void Preorder(Node* root){
	if(!root)return;
	cout<<root->data<<" ";
	Inorder(root->left);
	Inorder(root->right);
}
int main(){
	int pre[] = {10,5,1,7,40,50};
	int size = sizeof(pre)/sizeof(pre[0]);
	Node* root = ConstructTree(pre,size);
	cout<<"Inorder Traversal of the constructed tree: ";
	Inorder(root);
	cout<<endl;
	cout<<"Preorder Traversal of the constructed tree: ";
	Preorder(root);
    return 0;
}