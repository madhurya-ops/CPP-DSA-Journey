#include<iostream>
using namespace std;

// inorder traversal:  left + root + right 
struct TreeNode{
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;   
    stack<TreeNode*> st;
    TreeNode* node = root;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node -> left;
        }
        else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node -> val);
            node = node -> right;
        }
    }
    return inorder;
}

int main(){
// Tree
TreeNode *root = new TreeNode(1);
root -> left = new TreeNode(2);
root -> right = new TreeNode(3);
root -> left -> left = new TreeNode(4);
root -> left -> right = new TreeNode(5);
root -> left -> right -> left = new TreeNode(8);
root -> right -> left = new TreeNode(6);
root -> right -> right = new TreeNode(7);
root -> right -> right -> left= new TreeNode(9);
root -> right -> right -> right = new TreeNode(10);

vector<int> ans = inorderTraversal(root);

for(auto it : ans){
    cout << it << ", ";
}
cout << endl;
}