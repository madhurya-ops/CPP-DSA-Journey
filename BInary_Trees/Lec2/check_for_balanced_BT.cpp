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

// calc the height of the tree
// Balanced BT: height(left) - height(right) <= 1
// return the height inside a bool func
// if bool func return -1(false) then the tree is unbalanced
int dfsHeight(TreeNode* root){
    if(root == NULL) return 0;
        
    int leftHeight = dfsHeight(root -> left);
    if(leftHeight == -1) return -1;

    int rightHeight = dfsHeight(root -> right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;      
}

int main(){
// Tree
TreeNode* root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root ->right ->left = new TreeNode(4);
root -> right -> right = new TreeNode(6);
root -> right -> left -> left = new TreeNode(5);

cout << isBalanced(root);
}