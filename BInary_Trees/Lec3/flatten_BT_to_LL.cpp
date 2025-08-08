#include<iostream>
using namespace std;

// using the morris traversal to flatten the tree to a LL
// practise on multiple BT to better grasp the concept
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while(cur != NULL){
        if(cur->left != NULL){
            TreeNode* prev = cur->left;
            while(prev->right) {
                prev = prev -> right;
            }
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}

void printLL(TreeNode* head){
    while(head != nullptr){
        cout << head -> val << " ";
        head = head -> right;
    }
    cout << endl;
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

flatten(root);

//print the LL
printLL(root);
}