#include<iostream>
using namespace std;

int spanningTree(int v, vector<vector<int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(v, 0);
    // {wt, node}
    // push the parent as well when the edges of the MST are to be returned
    pq.push({0, 0});
    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1) continue;
        // adding to MST
        vis[node] = 1;
        sum += wt;
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];
            if(!vis[adjNode]){
                pq.push({edgeWt, adjNode});
            }
        }
    }
    return sum;
}

void addEdge(vector<vector<int>> adj[], int u, int v, int wt){
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

int main(){
    int v = 5;
    vector<vector<int>> adj[v];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 0, 3, 1);
    addEdge(adj, 1, 3, 4);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 2, 4, 7);

    cout << spanningTree(v, adj);
}