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

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    unsigned long long ans = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long minn = q.front().second; // to make the id starting from 0
        unsigned long long first = 0, last = 0;

        for (int i = 0; i < size; ++i) {
            unsigned long long cur_id = q.front().second - minn;
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0) first = cur_id;
            if (i == size - 1) last = cur_id;

            if (node->left) {
                q.push({node->left, cur_id * 2 + 1});
            }
            if (node->right) {
                q.push({node->right, cur_id * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return static_cast<int>(ans);
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

cout << widthOfBinaryTree(root);
}