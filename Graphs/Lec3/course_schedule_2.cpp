#include<iostream>
using namespace std;

// return if the given sequence can be performed in the given order
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto &it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    // store the indegrees of each node
    vector<int> indegree(numCourses, 0);
    for(int i = 0; i < numCourses; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    // push the node in the q with indegree = 0
    queue<int> q;
    for(int i = 0; i < numCourses; i++){
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
        
    if(topo.size() == numCourses) return topo;
    return {};
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    vector<int> result = findOrder(numCourses, prerequisites);

    for(auto it : result){
        cout << it << " ";
    }
    cout << endl;
}