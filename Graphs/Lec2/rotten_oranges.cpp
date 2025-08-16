#include<iostream>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // {{r, c}, t}
    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];

    // pushing the rotten oranges in the queue
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    // directions in which the oranges can rot: top, right, down and left
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        // traversing in the 4 directions(within bounds) to rot the oranges
        for(int i = 0; i < 4; i++){
            int nRow = r + drow[i];
            int nCol = c + dcol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 2;
            }
        }
    }

    // checking if there is any fresh orange remaining in the given matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
    }

    // return the time it took to rot every orange
    return tm;
}


int main(){
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << orangesRotting(grid);
}