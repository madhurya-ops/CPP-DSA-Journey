#include<iostream>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
    // to check if the node can be assigned with a color "col"
    for(int k = 0; k < n; k++){
        if(k != node && graph[k][node] == 1 && color[k] == col) return false;
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]){
    // base condition
    if(node == N){
        return true;
    }

    // to check and place valid colors at nodes
    for(int i = 0; i <= m; i++){
        if(isSafe(node, color, graph, N, i)){
            color[node] = i;
            if(solve(node+1, color, m, N, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

int main(){
    int N = 5; // Number of nodes
    int m = 3; // Number of colors

    // Initialize color array
    int color[101] = {0}; // all colors set to 0 initially

    // Build adjacency matrix
    bool graph[101][101] = {false};

    vector<pair<int, int>> edges = {
        {0,1}, {0,4}, {1,2}, {1,3}, {1,4}, {3,4}
    };

    for (auto [u, v] : edges) {
        graph[u][v] = true;
        graph[v][u] = true; // undirected
    }

    if (solve(0, color, m, N, graph)) {
        cout << "Graph can be colored using " << m << " colors:\n";
        for (int i = 0; i < N; i++) {
            cout << "Node " << i << " -> Color " << color[i] << "\n";
        }
    } else {
        cout << "Graph cannot be colored using " << m << " colors.\n";
    }

    return 0;
}