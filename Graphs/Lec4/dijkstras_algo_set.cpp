#include<iostream>
#include <set>
using namespace std;

vector<int> dijkstra(int v, vector<vector<vector<int>>>& adj, int src){
    set<pair<int, int>> st;
    vector<int> dist(v, 1e9);
    
    st.insert({0, src});
    dist[src] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];

            if(dis + edgeWt < dist[adjNode]){
                // erase the larger dist in the set 
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode], adjNode});
                }
                // new dist
                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
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