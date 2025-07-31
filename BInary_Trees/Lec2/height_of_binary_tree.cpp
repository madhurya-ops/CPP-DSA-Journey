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

// max depth of a tree (recursive soln)
// formula: 1 + max(leftHeight, rightHeight)
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return 1 + max(leftHeight, rightHeight);
    }

int main(){
// Tree
TreeNode* root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root ->right ->left = new TreeNode(4);
root -> right -> right = new TreeNode(6);
root -> right -> left -> left = new TreeNode(5);

cout << maxDepth(root);
}