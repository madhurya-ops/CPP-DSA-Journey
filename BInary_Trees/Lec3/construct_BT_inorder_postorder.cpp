#include<iostream>
using namespace std;

// constructing a unique BT, given: postorder, inorder
// Reference: https://www.youtube.com/watch?v=LgLRTaEMRVc
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTrees(vector<int> &postorder, int postStart, int postEnd, 
    vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mpp){
        if(postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root -> left = buildTrees(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, mpp);
        root -> right = buildTrees(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mpp);

        return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(postorder.size() != postorder.size()) return nullptr;

    unordered_map<int, int> mpp;
    for(int i = 0; i < inorder.size(); i++){
        mpp[inorder[i]] = i;
    }
    TreeNode* root = buildTrees(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
        
    return root;
}
