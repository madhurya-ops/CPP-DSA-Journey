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

bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    if(left == NULL || right == NULL) return left == right;
    if(left -> val != right -> val) return false;
    return isSymmetricHelp(left->left, right->right) 
        && isSymmetricHelp(left->right, right-> left);
}

bool isSymmetric(TreeNode* root) {
    return root == NULL || isSymmetricHelp(root -> left, root -> right);    
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> left -> left = new TreeNode(3);
root -> left -> right = new TreeNode(4);
root -> right = new TreeNode(2);
root -> right -> left = new TreeNode(4);
root -> right -> right = new TreeNode(3);

cout << isSymmetric(root);
}