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

int findFloor(TreeNode* root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){
            floor = root->val;
            return floor;
        }
        if(key > root -> val){
            floor = root -> val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}

int main(){
// Tree
struct TreeNode* root = new TreeNode(4);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(1);
root -> left -> right = new TreeNode(3);

cout << findFloor(root, 6);
}