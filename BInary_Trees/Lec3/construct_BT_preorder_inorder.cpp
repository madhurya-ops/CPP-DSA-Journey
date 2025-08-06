#include<iostream>
using namespace std;

// constructing a unique BT, given: preorder, inorder
// Reference: https://www.youtube.com/watch?v=aZNaLrVebKQ
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTrees(vector<int> &preorder, int preStart, int preEnd, 
    vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mpp){
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root -> val];
        int numsLeft = inRoot - inStart;

        root -> left = buildTrees(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mpp);
        root -> right = buildTrees(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);

        return root;
}
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> mpp; // mapping the inorder
    for(int i = 0; i < inorder.size(); i++){
        mpp[inorder[i]] = i;
    }
    TreeNode* root = buildTrees(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
        
    return root;
} 
