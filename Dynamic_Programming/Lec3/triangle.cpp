#include<iostream>
using namespace std;

// recursion
int f1(int i, int j, vector<vector<int>> &triangle){
    int n = triangle.size();
    if(i == n - 1) return triangle[n - 1][j];

    int d = triangle[i][j] + f1(i + 1, j, triangle);
    int dg = triangle[i][j] + f1(i + 1, j + 1, triangle);

    return min(d, dg);
}

// memoization
int f2(int i, int j, int n, int m, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    if(i == n - 1) return triangle[n -1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int d = triangle[i][j] + f2(i + 1, j, n, m, triangle, dp);
    int dg = triangle[i][j] + f2(i + 1, j + 1, n, m, triangle, dp);

    return dp[i][j] = min(d, dg);
}

// tabulation
int f3(vector<vector<int>> &triangle, vector<vector<int>> &dp){
    int n = triangle.size();
    
    for(int j = 0; j < n; j++){
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            int d = triangle[i][j] + dp[i + 1][j];
            int dg = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(d, dg);
        }
    }
    return dp[0][0];
}

// space optimized
int f4(vector<vector<int>> &triangle){
    int n = triangle.size();
    vector<int> down(n);
    for(int j = 0; j < n; j++){
        down[j] = triangle[n - 1][j];
    }

    for(int i = n - 2; i >= 0; i--){
        vector<int> curr(n);
        for(int j = i; j >= 0; j--){
            int d = triangle[i][j] + down[j];
            int dg = triangle[i][j] + down[j + 1];
            curr[j] = min(d, dg);
        }
        down = curr;
    }
    return down[0];
}

int main(){
    vector<vector<int>> triangle = {
        {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}
    };
    int n = triangle.size();
    int m = triangle[0].size();

    vector<vector<int>> dp(n);
    for(int i = 0; i < n; i++){
        dp[i].resize(triangle[i].size(), -1);
    }

    // cout << f2(0, 0, n, m, triangle, dp);
    cout << f4(triangle);
}