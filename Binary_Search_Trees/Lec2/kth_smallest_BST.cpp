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

// doing inorder traversal to find the kthSmallest
void inorder(TreeNode* root, int &cnt, int k, int &kSmallest){
    if(!root || cnt >= k) return;
    
    // searching on the left side of the tree
    inorder(root -> left, cnt, k, kSmallest);
    cnt++; // increase the cnt with every node visited
    if(cnt == k){
        kSmallest = root -> val;
        return;
    }
    // searching on the right side of the tree, if the key is not present on the left side
    inorder(root->right, cnt, k, kSmallest);
}

int kthSmallest(TreeNode* root, int k) {
    int kSmallest = INT_MIN;
    int cnt = 0;

    inorder(root, cnt, k, kSmallest);

    return kSmallest;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

cout << kthSmallest(root, 3);
}