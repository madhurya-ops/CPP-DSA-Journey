#include<iostream>
using namespace std;

// function to do the dfs traversal in the graph
bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;

    //  traverse for adjacent nodes
    for(auto it : adj[node]){
        // when the node is not visited
        if(!vis[it]){
            if(dfsCheck(it, adj, vis, pathVis) == true) return true; 
        }
        // if the node has been previosly visited
        // but the node has to be visited on the same path
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

// function to detect a cycle in a directed graph 
bool isCyclic(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(dfsCheck(i, adj, vis, pathVis)) return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main(){
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0); // back edge creates a cycle
    addEdge(adj, 2, 3);

    cout << isCyclic(V, adj);
}