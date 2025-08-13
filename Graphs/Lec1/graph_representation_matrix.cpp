#include<iostream>
using namespace std;

/*
space required for undirected graph: O(NxN), where N --> nodes in the graph
*/
int main(){
    int n, m;
    cin >> n >> m;
    // undirected graph stored below
    int adj[n+1][m+1];
    for(int i = 0; i<m; i++){ 
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}