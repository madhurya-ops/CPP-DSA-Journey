#include<iostream>
using namespace std;

// To return: number of nodes traversed
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //  Q => {dist, {row, col}}
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 1;
    q.push({1, {0, 0}});

    // Edge cases
    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
    if (n == 1 && m == 1) return 1;
        
    while(!q.empty()){
        // extract dist, row, col from the first element in the Q and pop it
        auto it = q.front();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        q.pop();

        // traversing in all 8 directions of a node
        for(int delRow = -1; delRow <= 1; delRow++){
            for(int delCol = -1; delCol <= 1; delCol++){  
                int nRow = row + delRow;
                int nCol = col + delCol;

                // update the dist and push in the q
                // if destination reached, return dist + 1
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && grid[nRow][nCol] == 0 && dis + 1 < dist[nRow][nCol]){
                    dist[nRow][nCol] = 1 + dis;
                    if(nRow == n - 1 && nCol == n - 1) return dis + 1;
                    q.push({dis + 1, {nRow, nCol}});
                }
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> grid = {
        {0,0,0},
        {1,1,0},
        {1,1,0}
    };

    cout << shortestPathBinaryMatrix(grid);

}