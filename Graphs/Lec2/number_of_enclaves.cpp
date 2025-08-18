#include<iostream>
using namespace std;

// problem similar to surrounded regions
int numEnclaves(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // traversing around the borders to store the 1s at the border
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){  
            // first row, first col, last row, last col
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
            
        // traverse all 4 directions
        // to mark the 1s connected to the borders as visited
        // so that they are not considered while returning the land cell count
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
            }   
        }
    }

    // count the 1s in the matrix which have not been visited previously
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 && !vis[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << numEnclaves(grid);
}