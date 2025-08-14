#include<iostream>
using namespace std;

// dfs traversal in each province
void dfs(int node, vector<int> adjLs[], vector<int>& vis){
    vis[node] = 1;
    for(auto it : adjLs[node]){
        // mark the nodes visited simultaneously
        if(!vis[it]){
            dfs(it, adjLs, vis);
        }
    }
}

int findCircleNum(vector<int> adjList[], int n) {
    vector<int> vis(n+1, 0);
    int cnt = 0; 
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            // cnt the provinces
            cnt++;
            dfs(i, adjList, vis); // doing a dfs traversal for each province
        }
    }
    return cnt;
}

void addEdge(vector<int> adjLs[], int u, int v){
    adjLs[u].push_back(v);
    adjLs[v].push_back(u);
}

int main(){
    int n = 8;
    vector<int> adj[n+1];

    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 7, 8);

    cout << findCircleNum(adj, n);
}