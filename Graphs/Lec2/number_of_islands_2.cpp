#include<iostream>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 0;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // traverse for all the neighbours and mark them if it is a land
        for(int delRow = -1; delRow <= 1; delRow++){
            for(int delCol = -1; delCol <= 1; delCol++){
                int nRow = row + delRow;
                int nCol = col + delCol;
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});

                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                bfs(row, col, vis, grid);
                // every time you call the BFS, you are searching for a new piece of land
                // therefore no. of times BFS is called is the ans;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << numIslands(grid);
}