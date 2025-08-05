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

// storing the nodes along with their parent nodes
void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current -> left){
            parent_track[current -> left] = current;
            q.push(current -> left);
        }
        if(current -> right){
            parent_track[current -> right] = current;
            q.push(current -> right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track; // to store the parents
    markParents(root, parent_track, target);

    unordered_map<TreeNode*, bool> visited; // to store the visited nodes 
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int cur_level = 0; // distance travelled radially outwards from the targert
    while(!q.empty()){
        int size = q.size();
        if(cur_level++ == k) break; // if distance == k, stop the traversal
        // taking out elements from the queue
        // traversing each of the radially outeards
        // until the distance == k
        // while checking if they are already visited or not
        // if not visited, adding them to the queue
        for(int i = 0; i < size; i++){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left && !visited[current -> left]){
                q.push(current -> left);
                visited[current -> left] = true;
            }
            if(current -> right && !visited[current -> right]){
                q.push(current -> right);
                visited[current -> right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    // store the ans in a vector and return
    vector<int> result;
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        result.push_back(current -> val);
    }
    return result;
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

vector<int> ans = distanceK(root, root -> right, 2);

for(auto it : ans){
    cout << it << " ";
}
cout << endl;
}