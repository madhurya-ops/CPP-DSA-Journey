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

// class to define how to store the val of each node
class NodeVal{
public:
    int maxNode, minNode, maxSize;
    
    // constructor
    NodeVal(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeVal largestBSTSubtreeHelper(TreeNode* root){
    // an empty tree is a BST of size 0
    if(!root){
        return NodeVal(INT_MAX, INT_MIN, 0);
    }

    // get values from left and right subtree of current tree
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // current node is greater than max in left AND smaller than min in right, it is a BST
    if(left.maxNode < root->val && root->val < right.minNode){
        // It is a BST
        return NodeVal(min(left.minNode, root->val), 
            max(right.maxNode, root->val), (1 + left.maxSize + right.maxSize));
    }

    // otherwise return [-inf, inf], so that the parent cant be a valid BST
    return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root){
    return largestBSTSubtreeHelper(root).maxSize;
}

int main(){
// Tree
TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    cout << largestBSTSubtree(root);
}