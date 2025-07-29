#include<iostream>
using namespace std;

// postorder traversal: root + left + right 
struct TreeNode{
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void postorder(TreeNode *root, vector<int> &arr){
    if(root == nullptr) return;
    postorder(root -> left, arr);
    postorder(root -> right, arr);
    arr.push_back(root -> val); 
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> arr;

    postorder(root, arr);

    return arr;
}

int main(){
// Tree
TreeNode *root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root -> left -> left = new TreeNode(4);
root -> left -> right = new TreeNode(5);
root -> left -> right -> left = new TreeNode(8);
root -> right -> left = new TreeNode(6);
root -> right -> right = new TreeNode(7);
root -> right -> right -> left= new TreeNode(9);
root -> right -> right -> right = new TreeNode(10);

vector<int> ans = postorderTraversal(root);

for(auto it : ans){
    cout << it << ", ";
}
cout << endl;
}