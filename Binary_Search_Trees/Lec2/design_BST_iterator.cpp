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

class BSTIterator {
private: stack<TreeNode*> st;

// pushing all the left nodes in the stack
private: 
void pushAll(TreeNode* node){
    for(; node != NULL; st.push(node), node = node-> left);
}

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // returns the next value of node in the traversal
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    // validates if the next node exists or not
    bool hasNext() {
        return !st.empty();
    }
};