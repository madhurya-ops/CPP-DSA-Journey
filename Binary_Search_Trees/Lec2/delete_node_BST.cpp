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

// finds the right-most node in a sub-tree
TreeNode* finalLastRight(TreeNode* root){
    if(root -> right == NULL) return root;
    return finalLastRight(root -> right);
}

// restructures the links between the nodes, to delete a node
TreeNode* helper(TreeNode* root){
    if(root -> left == NULL) return root -> right;
    if(root -> right == NULL) return root -> left;
    TreeNode* rightChild = root -> right;
    TreeNode* lastRight = finalLastRight(root -> left);
    lastRight -> right = rightChild;
    return root -> left;
}

// finds the node to be deleted, passes on to the helper function
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root -> val == key) return helper(root);
    TreeNode* dummy = root;
    while(root != NULL){
        if(root -> val > key){
            if(root -> left != NULL && root -> left -> val == key){
                root -> left = helper(root->left);
                break;
            }
            else{
                root = root -> left;
            }
        }
        else{
            if(root -> right != NULL && root -> right -> val == key){
                root -> right = helper(root -> right);
                break;
            }
            else{   
                root = root -> right;
            }
        }
    }
    return dummy;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

deleteNode(root, 7);

}