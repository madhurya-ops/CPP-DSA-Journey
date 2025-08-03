#include<iostream>
#include<set>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
        
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node -> val);
        if(node -> left) todo.push({node -> left, {x - 1, y + 1}});
        if(node -> right) todo.push({node -> right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col; // stores all the elments in a level
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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

vector<vector<int>> ans = verticalTraversal(root);

for(auto comp : ans){
    for(auto it : comp){
        cout << it << " ";
    }
    cout << endl;
}

}