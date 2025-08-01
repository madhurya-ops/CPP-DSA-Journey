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

int maxPathDown(TreeNode* node, int &maxi){
    if(node ==  NULL) return 0;
    int leftSum = max(0, maxPathDown(node->left, maxi));
    int rightSum = max(0, maxPathDown(node->right, maxi));
    maxi = max(maxi, leftSum + rightSum + node->val);
    return (node -> val) + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;    
}

int main(){
// Tree
TreeNode* root = new TreeNode(-10);
root -> left = new TreeNode(9);
root -> right = new TreeNode(20);
root ->right -> left = new TreeNode(15);
root -> right -> right = new TreeNode(7);

cout << maxPathSum(root);
}