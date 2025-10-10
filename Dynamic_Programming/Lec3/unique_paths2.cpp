#include<iostream>
using namespace std;

// Space Optimized
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> prev(n);

    for(int i = 0; i < m; i++){
        vector<int> curr(n);
        for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j] == 1) curr[j] = 0;
            else if(i == 0 && j == 0) curr[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j - 1];
                curr[j] = up + left;    
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main(){
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << uniquePathsWithObstacles(obstacleGrid);
}