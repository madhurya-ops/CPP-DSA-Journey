#include<iostream>
#include <map>
using namespace std;
// The last elment of each vertical is the bottom view element
// take the value form the map in the ascending order of the vertical lines

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, int> mpp; // line, node -> val
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        
        mpp[line] = node -> val;
        if(node -> left) q.push({node -> left, line - 1});
        if(node -> right) q.push({node -> right, line + 1});
    }

    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
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

vector<int> ans = bottomView(root);

for(auto it : ans){
    cout << it << " ";
}
cout << endl;
}