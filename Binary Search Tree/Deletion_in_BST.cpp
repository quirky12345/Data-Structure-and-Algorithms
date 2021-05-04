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
Node* insert(Node* root,int key){
	if(root == NULL)return new Node(key);
	if(key < root->data)root->left = insert(root->left,key);
	else root->right = insert(root->right,key);
	return root;
}
void inorder(Node* root){
	if(!root)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* inordersuccessor(Node* root){
	struct Node* current = root;
	while(current && current->left!=NULL)current = current->left;
	return current;
}
Node* deleteNode(Node* root,int key){
	if(!root)return NULL;
	if(key < root->data)root->left = deleteNode(root->left,key);
	else if(key > root->data)root->right = deleteNode(root->right,key);
	else {
		if(root->left == NULL and root->right == NULL){
			return NULL;
		}
		else if(root->left == NULL){
            struct Node* temp = root->right;
            delete(root);
            return temp;
		}
		else if(root->right == NULL){
            struct Node* temp = root->left;
            delete(root);
            return temp;
		}
		else {
			struct Node* temp = inordersuccessor(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root;
}
int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);
    
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    return 0;
	return 0;
}