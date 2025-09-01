#include<iostream>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    // reversing the links of the given graph
    vector<vector<int>> adjRev(V);
    vector<int> indegree(V);
    for(int i = 0; i < V; i++){
        // i -> it
        // it -> i
        for(auto it : graph[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    // puhsing the node in the q with indegree = 0
    queue<int> q;
    vector<int> safeNodes;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    // exploring all the nodes which are safe
    // i.e. all the nodes that either lead to terminal nodes or are terminal nodes
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node); // push the node in the ans arr
        for(auto it : adjRev[node]){
            // decrement the indegree
            // if indegree of a node is 0, push it in the q
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    // sort the ans before returning
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = eventualSafeNodes(graph);
    for(auto it : ans){
        cout << it << " ";
    }
}