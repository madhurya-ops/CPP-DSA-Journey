#include<iostream>
using namespace std;
// input a tree and convert it to follow the child sum property 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void changeTree(TreeNode* root){
    if(!root) return;
    // calc the values of the left and right child, if they exist
    int child = 0; 
    if(root -> left) child += root -> left -> val;
    if(root -> right) child += root -> right -> val;

    // if the children sum property is followed
    // assign the root with the sum of children, if root < child
    if(child >= root -> val) root -> val = child;
    // otherwise assign the value of root to the left and right child
    else{
        if(root -> left) root -> left -> val = root -> val;
        else if(root->right) root -> right -> val = root -> val;
    }

    changeTree(root -> left);
    changeTree(root -> right);

    // Calculate the total sum of the
    // values of the left and right
    // children, if they exist.
    int tot = 0;
    if(root -> left) tot += root -> left -> val;
    if(root -> right) tot += root -> right -> val;
    // to check if the node is leaf node or not
    // then update the value of root to "tot"
    if(root -> left || root -> right) root -> val = tot;
}