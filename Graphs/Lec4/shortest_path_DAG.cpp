#include<iostream>
using namespace std;

// sorting the node topologically so that they are traversed in a sequential manner
// using the DFS approach
void topoSort(int node, vector<int> &vis, vector<pair<int, int>> adj[], 
    stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        int v = it.first;
        if(!vis[v]){
            topoSort(v, vis, adj, st);
        }
    }
    st.push(node);
}

// n -> number of nodes
// m -> number of edges
vector<int> shortestPath(int n, int m, vector<int> edges[]){
    // create the graph 
    vector<pair<int, int>> adj[n];
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // find the topo sort
    vector<int> vis(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            topoSort(i, vis, adj, st);
        }
    }

    // step-2: find the shortest diatances
    vector<int> dist(n, INT_MAX);
    dist[0] = 0; // when source node not given, take 0 as source node
    while(!st.empty()){
        int node = st.top();
        st.pop();
        // pop the elements from the stack and traverse the adj nodes
        // add the adj node dist to the current node dist
        // if the dist is less, then replace it with the current dist
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] != INT_MAX && dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}

int main(){
    int n = 6;
    int m = 7;
    vector<int> edges[] = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    vector<int> shortestDist = shortestPath(n, m, edges);
    for(auto it : shortestDist){
        if(it == INT_MAX) cout << "INF ";
        else cout << it << " ";
    }
    cout << endl;
}