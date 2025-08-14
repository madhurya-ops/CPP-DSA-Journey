#include<iostream>
using namespace std;

void helper(int node, vector<int> adj[], vector<int> vis, vector<int> &dfs){
    vis[node] = 1;
    dfs.push_back(node);

    // traverse all it's neighbours
    for(auto it : adj[node]){
        if(!vis[it]){
            helper(it, adj, vis, dfs);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    vis[0] = 1;
    int start = 0;
    vector<int> dfs;

    helper(start, adj, vis, dfs);
    return dfs;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


int main(){
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector <int> ans = dfsOfGraph(5, adj);
    printAns(ans);
}