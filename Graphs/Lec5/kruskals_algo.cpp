#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]); 
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int v, vector<vector<int>> adj[]){
    // convert the given adjacency list in a vector format
    vector<pair<int, pair<int, int>>> edges;
    // O(N + E)
    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int edgeWt = it[1];
            int node = i;
            edges.push_back({edgeWt, {node, adjNode}});
        }
    }

    DisjointSet ds(v);
    // sort the vector
    // O(MlogM)
    sort(edges.begin(), edges.end());
    int mstWt = 0;
    // pick one ({wt, {u, v}}) at a time,
    // calc ultimate parents of u and v
    // if u & v don't belong to the same component, make the union and increase the mst weight
    // O(M x 4 x alpha x 2)
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUParent(u) != ds.findUParent(v)){
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}

void addEdge(vector<vector<int>> adj[], int u, int v, int wt){
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

int main(){
    int v = 6;
    vector<vector<int>> adj[v];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 4, 6);
    addEdge(adj, 2, 4, 5);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 3, 5, 7);
    addEdge(adj, 4, 5, 8);

    cout << spanningTree(v, adj);
}