#include<iostream>
using namespace std;

// Recursive
int f1(int i, int j, vector<vector<int>>& grid){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e8;
    int up = grid[i][j] + f1(i - 1, j, grid);
    int left = grid[i][j] + f1(i, j - 1, grid);
    return min(up, left);
}

// memoization
int f2(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e8;

    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + f1(i - 1, j, grid);
    int left = grid[i][j] + f1(i, j - 1, grid);
    return dp[i][j] = min(up, left);
}

// tabulation
int f3(vector<vector<int>>& grid, vector<vector<int>> &dp){
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) dp[0][0] = grid[0][0];
            else{
                int up = 1e9;
                int left = 1e9;

                if(i > 0) up = grid[i][j] + dp[i - 1][j];

                if(j > 0) left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

// space optimized
int f4(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);
    for(int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) curr[j] = grid[i][j];
            else{
                int up = grid[i][j];
                if(i > 0) up += prev[j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += curr[j - 1];
                else left += 1e9;

                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n -1];
}

int main(){
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    // cout << f1(n - 1, m - 1,grid);
    cout << f3(grid, dp);
}