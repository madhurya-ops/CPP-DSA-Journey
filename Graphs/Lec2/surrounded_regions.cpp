#include<iostream>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat,
        int delRow[], int delCol[]){
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col] = 1;

    // check for 'O' on top, right, bottom and left
    for(int i = 0; i < 4; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
            !vis[nRow][nCol] && mat[nRow][nCol] == 'O'){
                dfs(nRow, nCol, vis, mat, delRow, delCol);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
        
    // for the first and last rows
    for(int j = 0; j < m; j++){
        // first row
        if(!vis[0][j] && board[0][j] == 'O'){
            dfs(0, j, vis, board, delRow, delCol);
        }

        // last row
        if(!vis[n-1][j] && board[n-1][j] == 'O'){
            dfs(n-1, j, vis, board, delRow, delCol);
        }
    }

    // for first and last col
    for(int i = 0; i < n; i++){
        // first col
        if(!vis[i][0] && board[i][0] == 'O'){
            dfs(i, 0, vis, board, delRow, delCol);
        }

        // last col
        if(!vis[i][m-1] && board[i][m-1] == 'O'){
            dfs(i, m-1, vis, board, delRow, delCol);
        }
    }

    // travering on the complete board 
    // converting all the O to X which are not visited (i.e. they were not on the border)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);

    for(auto comp : board){
        for(auto it : comp){
            cout << it << " ";
        }
        cout << endl;
    }
}