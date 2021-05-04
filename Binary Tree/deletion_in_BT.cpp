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
void deletelastkey(struct Node* root,struct Node* d_node){
    queue<Node*> q;
    q.push(root);
    struct Node* temp;
    while(!q.empty()){
      temp = q.front();
      q.pop();
      if(temp == d_node){
      	temp == NULL;
      	delete(d_node);
      	return;
      }
      if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
    return;
}
Node* deletion(struct Node* root,int key){
	if(root == NULL || root->data==key)return NULL;
	if(root->left == NULL && root->right == NULL)return root;
	struct Node* temp = NULL;
	struct Node* temp_here;
	queue<Node*> q;
	q.push(root);
    while(!q.empty()){
    	temp_here = q.front();
    	q.pop();
    	if(temp_here->data == key)temp = temp_here;
    	if(temp_here->left!=NULL)q.push(temp_here->left);
    	if(temp_here->right!=NULL)q.push(temp_here->right);
    }
    if(temp!=NULL){
        int x = temp_here->data;
        //struct Node* d_node = temp_here;
        //temp_here == NULL;
        //delete(d_node);
        deletelastkey(root,temp_here);
        temp->data = x;
    }
    return root;
}
void inorder(struct Node* temp)
{
    if (!temp)return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
int main(){
	struct Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);
    cout << "Inorder traversal before deletion : ";
    inorder(root);
    cout << endl;

    int key = 11;
    root = deletion(root, key);
    
    cout << "Inorder traversal after deletion : ";
    inorder(root);
    cout << endl;

	return 0;
}