#include<iostream>
using namespace std;

// recursive approach
int f1(int i, int j1, int j2, vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    if(i == n - 1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            if(j1 == j2) maxi = max(maxi, grid[i][j1] + f1(i+1, dj1 + j1, dj2 + j2, grid));
            else maxi = max(maxi, grid[i][j1] + grid[i][j2] + f1(i+1, dj1 + j1, dj2 + j2, grid));
        }
    }
    return maxi;
}

// memoized
int f2(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, 
    vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
        if(i == r - 1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f2(i+1, dj1 + j1, dj2 + j2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
}

// Tablulation
int f3(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    int n = grid.size();
    int m = grid[0].size();

    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
            if(j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
            else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){

                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        if(dj1 + j1 >= 0 && dj1 + j1 < m && dj2 + j2 >= 0 && dj2 + j2 < m)
                            value += dp[i+1][dj1 + j1][dj2 + j2];
                        else 
                            value += -1e8;
                        maxi = max(maxi, value);
                    }   
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1]; 
}

// space optimized: (3D to 2D) -> reducing one dimension
int f4(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));

    for(int j1 = 0; j1 < m; j1++){
        for(int j2 = 0; j2 < m; j2++){
            if(j1 == j2) front[j1][j2] = grid[n - 1][j1];
            else front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){

                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        if(dj1 + j1 >= 0 && dj1 + j1 < m && dj2 + j2 >= 0 && dj2 + j2 < m)
                            value += front[dj1 + j1][dj2 + j2];
                        else 
                            value += -1e8;
                        maxi = max(maxi, value);
                    }   
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m - 1]; 
}

int main(){
    vector<vector<int>> grid = {
      {2, 3, 1, 2},
      {3, 4, 2, 2},
      {5, 6, 3, 5}  
    };

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // cout << f2(0, 0, m - 1, n, m, grid, dp);
    // cout << f3(grid, dp);
    cout << f4(grid);
}