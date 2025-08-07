#include<iostream>
using namespace std;
// refer to the notes and vid for better understanding
// benefit of morris traversal: SC -> O(1)
// reference: https://www.youtube.com/watch?v=80Zug6D1_r4
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// this is a morris traversal for inorder search
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev -> right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

// this is a morris traversal for preorder search
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev -> right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root -> left -> left = new TreeNode(4);
root -> left -> right = new TreeNode(5);
root -> left -> right -> left = new TreeNode(6);
root -> left -> right -> right = new TreeNode(7);


}