#include<iostream>
using namespace std;

// postorder traversal:  left + right + root 
struct TreeNode{
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using 2 stacks
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postorder;
    stack<TreeNode*> st1, st2;
    if(root == NULL) return postorder;

    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root -> left != NULL){
            st1.push(root->left);
        }
        if(root -> right != NULL){
            st1.push(root -> right);
        }
    }

    while(!st2.empty()){
        postorder.push_back(st2.top() -> val);
        st2.pop();
    }

    return postorder;
}

// using 1 stack
vector<int> postorderIterative(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> postorder;
    TreeNode* curr = root;
    TreeNode* temp;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr -> left;
        }
        else{
            temp = st.top() -> right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp -> val);
                while(!st.empty() && st.top() -> right == temp){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp -> val);
                }
            }
            else{
                curr = temp;
            }
        }
    }
    return postorder;
}

int main(){
// Tree
TreeNode *root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(7);
root -> left -> left = new TreeNode(3);
root -> right -> left = new TreeNode(8);
root -> left -> left -> right= new TreeNode(4);
root -> left -> left -> right -> right = new TreeNode(5);
root -> left -> left -> right -> right -> right = new TreeNode(6);

vector<int> ans = postorderIterative(root);

for(auto it : ans){
    cout << it << ", ";
}
cout << endl;
}