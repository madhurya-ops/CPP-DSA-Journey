#include<iostream>
using namespace std;

vector<int> bellmanFord(int v, vector<vector<int>> &edges, int src){
    vector<int> dist(v, 1e8);
    dist[src] = 0;

    // Relaxation V - 1 times
    for(int i = 0; i < v - 1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // checking for negative cycle inside the graph 
    // running one extra iteration
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }   

    return dist;
}

int main(){
    int v = 2;
    int src = 0;
    vector<vector<int>> edges = {
        {0, 1, 9}
    };
    
    vector<int> ans = bellmanFord(v, edges, src);
    for(auto it : ans){
        cout << it << " ";
    }
}