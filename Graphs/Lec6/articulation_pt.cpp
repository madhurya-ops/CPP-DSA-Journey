#include<iostream>
using namespace std;

int timer = 0;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin,
    vector<int> &low, vector<int> &mark, vector<int> adj[]){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(!vis[it]){
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    if(child > 1 && parent == -1){
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<int> mark(n, 0);

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, -1, vis, tin, low, mark, adj);
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(mark[i] == 1){
            ans.push_back(i);
        }
    }
    if(ans.size() == 0) return {-1};
    return ans;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int n = 5;
    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);

    vector<int> result = articulationPoints(n, adj);

    cout << "Articulation Points: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}