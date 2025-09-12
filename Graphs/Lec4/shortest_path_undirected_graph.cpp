#include<iostream>
using namespace std;

// finding the shortest path in an undirected graph
// using BFS algo
vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int src){
    // creating an adjacency list 
    vector<int> adj[n];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // create a dist vector and queue 
    // src node has dist = 0 and it's the initial val in the queue
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    // pop the elements of the q and traverse their adjacent nodes
    // update the dist of the node if a smaller path is found
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    // returning the ans
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i]; 
        }
    }
    return ans;
}

int main(){
    // n -> nodes & m -> edges
    int n = 8;
    int m = 10;
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {1,4},
        {2,5}, {2,6}, {3,7}, {4,5},
        {5,7}, {6,7}
    };

    int src = 0; // starting node
    vector<int> result = shortestPath(edges, n, m, src);

    for(auto it : result){
        cout << it << " ";
    }
    cout << endl;
}