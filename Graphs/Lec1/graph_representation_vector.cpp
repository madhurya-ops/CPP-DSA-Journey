#include<iostream>
using namespace std;

/*
space required for undirected graph: O(2E), where E --> edges
space required for directed graph: O(E)
*/
int main(){
    int n, m;
    cin >> n >> m;
    // undirected graph stored below
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // u <---> v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*
    for directed graph:
    for(int i = 0; i < m; i++){
        // u ---> v
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    */

    return 0;
}