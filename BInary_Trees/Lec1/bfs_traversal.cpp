#include<iostream>
using namespace std;

// level order traversal: level wise 
struct TreeNode{
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
            level.push_back(node -> val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
// Tree
TreeNode *root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root -> left -> left = new TreeNode(4);
root -> left -> right = new TreeNode(5);
root -> right -> left = new TreeNode(6);
root -> right -> right = new TreeNode(7);

vector<vector<int>> ans = levelOrder(root);

for(auto comp : ans){
    for(auto it : comp){
        cout << it << " ";
    }
    cout << endl;
}
cout << endl;
}