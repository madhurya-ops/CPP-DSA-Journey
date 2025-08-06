#include<iostream>
#include <map>
using namespace std;

template<typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// travelling radially outwards from the target 
// keeping a check of the visited elements
// incrementing the step size with +1 every time
int findMaxDist(map<TreeNode<int>*, TreeNode<int>*> &mpp, TreeNode<int>* target){
    queue<TreeNode<int>*> q;
    q.push(target);
    map<TreeNode<int>*, int> vis;
    vis[target] = 1;
    int maxi = 0; // stores the time taken to burn the complete tree
    while(!q.empty()){
        int size = q.size();
        int fl = 0; // flag (to know if a node was burned or not)
        for(int i = 0; i < size; i++){
            auto node = q.front();
            q.pop();
            if(node -> left && !vis[node->left]){
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node -> right && !vis[node->right]){
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(mpp[node] && !vis[mpp[node]]){
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if(fl) maxi++; // if even a single node was burned, the maxi will be incremented
    }
    return maxi;
}

// mapping the parents to keep a track
TreeNode<int>* bfsToMapParents(TreeNode<int>* root, map<TreeNode<int>*, 
    TreeNode<int>*> &mpp, int start){
        queue<TreeNode<int>*> q;
        q.push(root);
        TreeNode<int>* res;
        while(!q.empty()){
            TreeNode<int>* node = q.front(); 
            if(node -> val == start) res = node;
            q.pop();
            if(node -> left){
                mpp[node -> left] = node;
                q.push(node -> left);
            }
            if(node -> right){
                mpp[node -> right] = node;
                q.push(node -> right);
            }
        }
        return res;
}

int timeToBurnTree(TreeNode<int>* root, int start){
    map<TreeNode<int>*, TreeNode<int>*> mpp; // to store the parents along with child(node)
    TreeNode<int>* target = bfsToMapParents(root, mpp, start); // find the parents
    // travel radially outwards from the target, one with increment of +1 at a time (step size)
    int maxi = findMaxDist(mpp, target); // finds the time taken to burn the BT
    return maxi;
}

int main(){
// Tree
TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(7);
    root->left->left = new TreeNode<int>(3);
    root->left->left->right = new TreeNode<int>(4);
    root->left->left->right->left = new TreeNode<int>(5);
    root->left->left->right->right = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(8);
    root->right->right->left = new TreeNode<int>(9);
    root->right->right->left->left = new TreeNode<int>(10);
    root->right->right->left->right = new TreeNode<int>(11);

    cout << timeToBurnTree(root, 7);
}