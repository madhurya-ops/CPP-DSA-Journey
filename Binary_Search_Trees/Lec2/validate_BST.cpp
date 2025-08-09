#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// chceking the if the BST is valid or not
// assigning range to each node: minVal < node < maxVal
bool checkValid(TreeNode* root , long minVal, long maxVal){
    if(root == NULL) return true;
    if(root->val >= maxVal || root->val <= minVal) return false;
    return checkValid(root->left, minVal, root->val) 
        && checkValid(root->right, root->val, maxVal);
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

cout << checkValid(root, LONG_MIN, LONG_MAX);
}