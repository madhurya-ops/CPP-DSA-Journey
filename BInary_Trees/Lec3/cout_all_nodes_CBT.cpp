#include<iostream>
using namespace std;

// calc the number of nodes in the complete binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// count the height of the left sub-tree
int findLeftHeight(TreeNode* node){
    int height = 0;
    while(node){
        height++;
        node = node -> left;
    }
    return height;
}

int findRightHeight(TreeNode* node){
    int height = 0;
    while(node){
        height++;
        node = node -> right;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if(root == NULL) return 0;

    int leftHeight = findLeftHeight(root);
    int rightHeight = findRightHeight(root);

    // if left and right subtree are of equal heights,
    // apply the formula: 2^(height) - 1
    if(leftHeight == rightHeight) return (1 << leftHeight) - 1;

    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(3);
root -> left -> left -> right = new TreeNode(4);
root -> left -> left -> right -> left = new TreeNode(5);
root -> left -> left -> right -> right = new TreeNode(6);
root -> right -> right = new TreeNode(8);
root -> right -> right -> left = new TreeNode(9);
root -> right -> right -> left -> left = new TreeNode(10);
root -> right -> right -> left -> right = new TreeNode(11);

cout << countNodes(root);
}