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

// recursive solution
TreeNode* build(vector<int> &preorder, int &i, int bound){
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    // creating a new node and incrementing i
    TreeNode* root = new TreeNode(preorder[i++]);
    // when going left, transferring node->val
    root -> left = build(preorder, i, root->val);
    // when going right, transferring upper bound
    root -> right = build(preorder, i, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

int main(){
vector<int> preorder = {8,5,1,7,10,12};

bstFromPreorder(preorder);
}