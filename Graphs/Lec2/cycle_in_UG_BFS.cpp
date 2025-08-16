#include<iostream>
using namespace std;

// detecting the cycle using bfs
bool detect(int src, vector<int> adj[], vector<int> vis){
    vis[src] = 1;
    queue<pair<int, int>> q;
    // {node, parent}
    q.push({src, -1}); 

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // if the node is previously visited 
            // and node's parent != adjacent node
            // then it means that the node has been visitd by some other node in the graph 
            else if(parent != adjacentNode){
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    // in case of connected components, this loop checks for all the nodes
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            // if the component cotains a cycle, reuturn true
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n = 9;
    vector<int> adj[10];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 7, 8);
    addEdge(adj, 7, 9);
    addEdge(adj, 8, 9);

    cout<< isCyclic(n, adj);
}