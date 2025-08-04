#include<iostream>
using namespace std;
// last node of every level is the right side view
// recursion solution for smaller code
// root + right + left

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> recursion(TreeNode* root, int level, vector<int> &res){
    if(root == NULL) return res;
    if(res.size() == level) res.push_back(root -> val);
    recursion(root -> right, level + 1, res);
    recursion(root -> left, level + 1, res);
    return res;
}    

int main(){
// Tree
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

vector<int> res;
vector<int> ans = recursion(root, 0, res);

for(auto it : ans){
    cout << it << " ";
}
cout << endl;
}