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

// traversing in the zig-zag fashion 
// lef to right = 1, right to left = 0
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == NULL){
        return result;
    }
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    bool leftToRight = true;

    while(!nodeQueue.empty()){
        int size = nodeQueue.size();
        vector<int> row(size);
        for(int i = 0; i < size; i++){
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);
            row[index] = node -> val;
                
            if(node -> left){
                nodeQueue.push(node -> left);
            }
            if(node -> right){
                nodeQueue.push(node -> right);
            }
        } // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main(){
// Tree
TreeNode* root = new TreeNode(-10);
root -> left = new TreeNode(9);
root -> right = new TreeNode(20);
root ->right -> left = new TreeNode(15);
root -> right -> right = new TreeNode(7);

vector<vector<int>> ans = zigzagLevelOrder(root);

for(auto comp : ans){
    for(auto it : comp){
        cout << it << " ";
    }
    cout << endl;
}
}