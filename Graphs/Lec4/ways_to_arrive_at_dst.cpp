#include<iostream>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    // creating adj list out of given matrix
    vector<pair<int, int>> adj[n];
    for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> dist(n, LLONG_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0LL, 0}); // {dist, node}
    int mod = (int)(1e9 + 7);

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        long long dis = it .first;

        if(dis > dist[node]) continue; // do not calc the path which is not the shortest

        for(auto it : adj[node]){
            int adjNode = it.first;
            long long edgeWt = it.second;

            // if the node is reached for the first time
            if(dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dis+edgeWt, adjNode});
                ways[adjNode] = ways[node];
            }
            // if the node has been previously reached
            else if(dis + edgeWt == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n-1] % mod;
}

int main(){
    int n = 2;
    vector<vector<int>> roads = {
        {1, 0, 10}
    };

    cout << countPaths(n, roads);
}