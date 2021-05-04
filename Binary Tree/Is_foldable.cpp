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
bool IsfoldableUtil(struct Node* l,struct Node* r){
	if(l==NULL && r == NULL){
		return true;
	}
	if(l==NULL || r == NULL)return false;
	return IsfoldableUtil(l->left,r->right)&&IsfoldableUtil(l->right,r->left);
}
bool Isfoldable(struct Node* root){
	if(root == NULL)return true;
	else return IsfoldableUtil(root->left,root->right);
}
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    if(Isfoldable(root))cout<<"Tree is foldable";
    else cout<<"Tree is not foldable";
	return 0;
}