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
void sumOfLongRootToLeafPathUtil(Node* root, int sum,int Len, int& maxLen, int& maxSum){
    if(root == NULL){
        if(maxLen<Len){
            maxLen = Len;
            maxSum = sum;
        }
        else if(maxLen == Len && maxSum < sum){
            maxSum = sum;
        }
        return;
    }
    sumOfLongRootToLeafPathUtil(root->left, sum + root->data,Len + 1, maxLen, maxSum);
    sumOfLongRootToLeafPathUtil(root->right, sum + root->data,Len + 1, maxLen, maxSum);
}
int sumOfLongRootToLeafPath(Node* root)
{
	if(root==NULL)return 0;
	int maxSum = INT_MIN,maxLen = 0;
	sumOfLongRootToLeafPathUtil(root,0,0,maxLen,maxSum);
	//cout<<maxSum;
	return maxSum;
	// Code here
}
int main(){
	Node* root = new Node(4);         /*        4        */
    root->left = new Node(2);         /*       / \       */
    root->right = new Node(5);        /*      2   5      */
    root->left->left = new Node(7);   /*     / \ / \     */
    root->left->right = new Node(1);  /*    7  1 2  3    */
    root->right->left = new Node(2);  /*      /          */
    root->right->right = new Node(3); /*     19          */
    root->left->right->left = new Node(19);
    cout<<"Sum: "<<sumOfLongRootToLeafPath(root)<<endl;
	return 0;
}