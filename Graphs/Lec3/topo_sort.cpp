#include<iostream>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it, st, vis, adj);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> vis(V);
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, st, vis, adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main(){
    int V = 6;
    vector<int> adj[V];

    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    vector<int> ans = topoSort(V, adj);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}