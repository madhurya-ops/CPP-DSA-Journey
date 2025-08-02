#include<iostream>
using namespace std;
// Boundary Traversal: anti-clockwise direction
// Step-1: Left Boundary excluding leaf nodes
// Step-2: Leaf Nodes (Preorder traversal: Root + Left + Right)
// Step-3: Right Boundary in reverse order, excluding the leaves

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Check: If the node is a leaf node or not
bool isLeaf(TreeNode* root) {
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode* root, vector<int> &res){
    TreeNode* cur = root -> left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur -> val);
        if(cur -> left) cur = cur -> left;
        else cur = cur -> right;
    }
}

void addRightBoundary(TreeNode* root, vector<int> &res){
    TreeNode* cur = root -> right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur -> val);
        if(cur -> right) cur = cur -> right;
        else cur = cur -> left;
    }
    for(int i = temp.size() - 1; i >= 0; i--){
        res.push_back(temp[i]);
    }
}

void addLeaves(TreeNode* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root -> val);
        return;
    } 
    if(root -> left) addLeaves(root -> left, res);
    if(root -> right) addLeaves(root -> right, res);
}

vector<int> printBoundary(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root -> val);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

int main(){
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

vector<int> ans = printBoundary(root);

for(auto it : ans){
    cout << it << " ";
}
cout << endl;
}