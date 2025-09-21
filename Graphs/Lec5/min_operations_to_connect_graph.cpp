#include<iostream>
using namespace std;

class DisjointSet{
public:
    vector<int> rank, parent, size;
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

int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    int cntExtra = 0;
    // using disjoint set DS make the connections
    for(auto it : connections){
        int u = it[0];
        int v = it[1];
        // for repetitive edges increase the count of "cntExtra" 
        if(ds.findUParent(u) == ds.findUParent(v)){
            cntExtra++;
        }
        // otherwise join the nodes
        else{
            ds.unionBySize(u, v);
        }
    }
    // count the number of ultimate parents in the graph
    // i.e number of components (nc)
    // if extraEdges >= (nc - 1) return the ans
    int cntConnnectedComp = 0;
    for(int i = 0; i < n; i++){
        if(ds.findUParent(i) == i) cntConnnectedComp++;
    }
    int ans = cntConnnectedComp - 1;
    if(cntExtra >= ans) return ans;
    return -1;
}

int main(){
    int n = 6;
    vector<vector<int>> connections = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}

    };

    cout << makeConnected(n, connections);
}