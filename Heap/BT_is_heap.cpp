#include<bits/stdc++.h>
using namespace std;
bool isHeap(struct Node * root){
    if(!root)return true;
    queue<Node*> q;
    q.push(root);
    bool null_here = false;
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if (temp->left){
            if (null_here || temp->left->data>= temp->data)return false;
            q.push(temp->left);
        }
        else null_here = true;
        if (temp->right){
            if (null_here || temp->right->data>= temp->data)return false;
            q.push(temp->right);
        }
        else null_here = true;
    }
    return true;
}
int main(){
	struct Node* root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);
 
    // Function call
    if (isHeap(root))cout << "Given binary tree is a Heap\n";
    else cout << "Given binary tree is not a Heap\n";
	return 0;
}