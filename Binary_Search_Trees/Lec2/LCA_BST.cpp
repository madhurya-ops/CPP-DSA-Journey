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

int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    int cur = root -> val;
    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root->val;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

TreeNode* p = new TreeNode(2);
TreeNode* q = new TreeNode(3);

cout << lowestCommonAncestor(root, p, q);
}