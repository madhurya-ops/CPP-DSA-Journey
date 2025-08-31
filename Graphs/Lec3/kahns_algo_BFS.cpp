#include<iostream>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
    // store the indegrees of each node
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    // push the node in the q with indegree = 0
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0) q.push(i);
    }

    // pop the node from q
    // decrement its adj nodes' indegree
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // node is in your topo sort
        // remove it from the indegree
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
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