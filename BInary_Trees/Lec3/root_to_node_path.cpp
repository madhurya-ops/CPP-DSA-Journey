#include<iostream>
using namespace std;
// Follow the inorder traversal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool getPath(TreeNode* root, vector<int> &arr, int x){
    if(!root) return false;
    arr.push_back(root -> val);
    if(root -> val == x) return true;
    if(getPath(root -> left, arr, x) || getPath(root -> right, arr, x)){
        return true;
    }
    arr.pop_back();
    return false;
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

vector<int> arr;
int x = 7;
cout << getPath(root, arr, x);
}