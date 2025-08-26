#include<iostream>
using namespace std;

bool dfs(int node, int newColor, vector<vector<int>> &graph, vector<int> &color){
    color[node] = newColor;
        
    for(auto it : graph[node]){
        if(color[it] == -1){
            if(!dfs(it, !newColor, graph, color)) return false;
        }
        else if(color[it] == newColor) return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i = 0; i < n; ++i){
        if(color[i] == -1){
            if(!dfs(i, 0, graph, color)) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    cout << isBipartite(graph);
}