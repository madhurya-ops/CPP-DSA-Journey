#include<iostream>
using namespace std;

// Searching in a BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// finding min in a BST
int findMin(TreeNode* root){
    if(root == NULL) return 0;
    TreeNode* current = root;
    while(current -> left){
        current = current -> left;
    }
    return current -> val;
}

// finding max in a BST
int findMax(TreeNode* root){
    if(root == NULL) return 0;
    TreeNode* current = root;
    while(current -> right != NULL){
        current = current -> right;
    }
    return current->val;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

cout << "Min val in tree is: " << findMin(root);
cout << endl;
cout << "Max val in tree is: " << findMax(root);
}