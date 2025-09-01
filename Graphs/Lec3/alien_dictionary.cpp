#include<iostream>
using namespace std;

// works for multiple components
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

string findOrder(string dict[], int n, int k){
    // creating a graph for the alien dict order
    vector<int> adj[k];
    for(int i = 0; i < n; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());
        for(int ptr = 0; ptr < len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    // sorting them topologically and returning as a string
    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for(auto it : topo){
        ans = ans + char(it + 'a');
    }
    return ans;
}

int main(){
    string alienDict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4;
    int n = sizeof(alienDict) / sizeof(alienDict[0]);

    string ans = findOrder(alienDict, n, k);

    cout << ans;
}