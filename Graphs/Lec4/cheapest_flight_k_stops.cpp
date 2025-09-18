#include<iostream>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // creating graph out of the given matrix
    vector<pair<int, int>> adj[n];
    for(auto it : flights){
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k) continue; // do not push this path in the q

        for(auto iter : adj[node]){
            int adjNode = iter.first;
            int edgeWt = iter.second;

            if(cost + edgeWt < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + edgeWt;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }

    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}

int main(){
    int n = 3;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };
    int src = 0;
    int dst = 2;
    int k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);
}