#include<iostream>
using namespace std;

// preorder + inorder + postorder traversal in one go 
struct TreeNode{
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preInPostTraversal(TreeNode *root){
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    
    if(root == NULL) return;

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2
        // push the left side of the tree
        if(it.second == 1){
            pre.push_back(it.first -> val);
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        // increment 2 to 3
        // push right
        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }
        // dont push it back again
        else{
            post.push_back(it.first->val);
        }
    }
}