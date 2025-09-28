#include<iostream>
#include <set>
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

bool isValid(int adjr, int adjc, int n){
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < n;
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n*n);
    // Step - 1 (connect components)
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(grid[row][col] == 0) continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for(int ind = 0; ind < 4; ind++){
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                    int nodeNo = (row * n) + col;
                    int adjNodeNo = (newr * n) + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    // Step - 2 (try converting every 0 -> 1)
    int mxSize = 0;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(grid[row][col] == 1) continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for(int ind = 0; ind < 4; ind++){
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if(isValid(newr, newc, n)){
                    if(grid[newr][newc] == 1){
                        components.insert(ds.findUParent(newr * n + newc));
                    }
                }
            }
            int sizeTot = 0;
            for(auto it : components){
                sizeTot += ds.size[it];
            }
            mxSize = max(mxSize, sizeTot + 1);
        }
    }
    for(int cellNo = 0; cellNo < n * n; cellNo++){
        mxSize = max(mxSize, ds.size[ds.findUParent(cellNo)]);
    }
    return mxSize;
}

int main(){
    vector<vector<int>> grid = {
        {1, 0}, {0, 1}
    };

    cout << largestIsland(grid);
}