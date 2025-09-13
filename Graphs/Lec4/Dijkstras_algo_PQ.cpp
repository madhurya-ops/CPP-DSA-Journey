#include<iostream>
using namespace std;

vector<int> dijkstra(int v, vector<vector<vector<int>>>& adj, int src){
    // declaring a min-heap using priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main(){
    int v = 6; // number of vertices (0–5)
    vector<vector<vector<int>>> adj(v);

    // creating edges (u -> v with weight w)
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int src = 0; // starting node

    vector<int> dist = dijkstra(v, adj, src);

    for(auto it : dist){
        cout << it << " ";
    }
    cout << endl;
}