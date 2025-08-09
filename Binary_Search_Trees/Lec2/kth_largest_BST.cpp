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
void reverseInorder(TreeNode* root, int &cnt, int k, int &kLargest){
    if(!root || cnt >= k) return;
    
    // searching on the right side of the tree
    reverseInorder(root -> right, cnt, k, kLargest);
    cnt++; // increase the cnt with every node visited
    if(cnt == k){
        kLargest = root -> val;
        return;
    }
    // searching on the left side of the tree, if the key is not present on the left side
    reverseInorder(root -> left, cnt, k, kLargest);
}

int kthLargest(TreeNode* root, int k) {
    int kLargest = INT_MIN;
    int cnt = 0;

    reverseInorder(root, cnt, k, kLargest);

    return kLargest;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

cout << kthLargest(root, 2);
}