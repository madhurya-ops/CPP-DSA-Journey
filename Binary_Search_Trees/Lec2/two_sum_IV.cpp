#include<iostream>
using namespace std;

// two sum problem in a BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// taking 2 pointers: left & right
// left: min, right: max
// moving these pointers with the help of next function in BSTIterator
// left and right are 2 objects of the class BSTIterator

class BSTIterator {
private: stack<TreeNode*> st;
// reverse -> true -> before(predecessor)
// reverse -> false -> next(successor)
bool reverse = true;

private: 
void pushAll(TreeNode* node){
    for(; node != NULL;){
        st.push(node);
        if(reverse == true){
            node = node -> right;
        }
        else{
            node = node -> left;
        }
    }
}

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // next
        BSTIterator left(root, false);
        // for before
        BSTIterator right(root, true);

        int i = left.next();
        int j = right.next();

        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = left.next();
            else j = right.next();
        }
        return false;
    }
};