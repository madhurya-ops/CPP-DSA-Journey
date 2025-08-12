#include<iostream>
using namespace std;

// two sum problem in a BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
// first, middle, last: store the violated vals
// prev : stores the prev node to the current node
private:
TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;

private:
void inorder(TreeNode* root){
    if(root == NULL) return;

    inorder(root -> left);
    if(prev != NULL && (root->val < prev->val)){
        // if this is the first violation, 
        // mark these 2 nodes as first and middle
        if(first == NULL){
            first = prev;
            middle = root;
        }
        // if this is a second violation, mark this as the last
        else{
            last = root;
        }
    }
    // mark the current node as the previous
    prev = root;
    inorder(root->right);
}

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

// to print the solution 
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(5);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

Solution s;
s.recoverTree(root);

inorderPrint(root);
}