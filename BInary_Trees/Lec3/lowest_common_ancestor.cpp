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

// the last element that matched in the paths of both the nodes is the ans
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root;
    }
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

TreeNode* ans = lowestCommonAncestor(root, root -> left -> left -> right, root -> right -> right -> left);
cout << ans -> val;
}