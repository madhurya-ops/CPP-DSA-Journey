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

bool isValid(int row, int col, int n, int m){
    return row >= 0 && row < n && col >= 0 && col < m;
}

vector<int> numberOfIslands(int n, int m, vector<vector<int>> &operators){
    // n -> rows, m -> cols
    DisjointSet ds(n * m);
    // to keep track of the visited nodes in the mat
    int vis[n][m];
    memset(vis, 0, sizeof vis); // fill the vis with 0 initially
    int cnt = 0;
    vector<int> ans;

    // for each operator (given), check if it is visited, if yes, push the cnt and continue
    // if not, mark as visited, increase the cnt, traverse it's neighbours
    for(auto it : operators){
        int row = it[0];
        int col = it[1];
        if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(isValid(nr, nc, n, m)){
                if(vis[nr][nc] == 1){
                    int nodeNo = (row * m) + col;
                    int adjNodeNo = (nr * m) + nc; 
                    if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }

    return ans;
}

int main(){
    int n = 3;
    int m = 3;
    vector<vector<int>> operators = {
        {0,0}, {0,1}, {1,2}, {2,1}, {1,1}
    };

    vector<int> ans = numberOfIslands(n, m, operators);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}