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

// diameter: longest path b/w 2 nodes
// path does not need to pass via root
// diameter of a node = leftHeight + rightHeight
int height(TreeNode *node, int &diameter){
    if(!node){
        return 0;
    }
    int leftHeight = height(node -> left, diameter);
    int rightHeight = height(node -> right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main(){
// Tree
TreeNode* root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root ->right -> left = new TreeNode(4);
root ->right -> left -> left = new TreeNode(5);
root ->right -> left -> left -> left = new TreeNode(9);
root -> right -> right = new TreeNode(6);
root -> right -> right -> right = new TreeNode(7);
root -> right -> right -> right -> right = new TreeNode(8);

cout << diameterOfBinaryTree(root);
}