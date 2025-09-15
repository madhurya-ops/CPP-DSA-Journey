#include<iostream>
using namespace std;

// n -> number of nodes
// m -> number of edges
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges){
    // making an adjacency list from the given graph "edges"
    vector<pair<int, int>> adj[n+1];
    for(auto it : edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // defining min heap using PQ
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, 1e9), parent(n+1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    dist[1] = 0;
    pq.push({0, 1});

    // traversing in the PQ
    while(!pq.empty()){
        // extract the node and dist val from the top element of the PQ
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        // traverse in it's adjacent nodes
        // calc dis, if better dis found
        // replace the current dist[node] and also update the parent of the node
        // push the updated dist in the PQ along with the node
        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // if no path found
    if(dist[n] == 1e9) return {-1};
    
    // Returning the path
    vector<int> path;
    int node = n;

    // start from the last node to the first node
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end()); // reverse the vector for path: start -> end
    return path;
}

int main(){
    int n = 5; // number of nodes
    int m = 6; // number of edges

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    vector<int> path = shortestPath(n, m, edges);

    for(auto it : path){
        cout << it << " ";
    }
    cout << endl;
}