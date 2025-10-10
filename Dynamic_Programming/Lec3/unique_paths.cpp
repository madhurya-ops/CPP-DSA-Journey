#include<iostream>
using namespace std;

// Recursive
int f1(int i, int j){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    int up = f1(i - 1, j);
    int left = f1(i, j - 1);

    return up + left;
}

// Memoized
int f2(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int up = f2(i - 1, j, dp);
    int left = f2(i, j - 1, dp);

    return dp[i][j] = up + left;
}

// Tabulation
int f3(int m, int n, vector<vector<int>> &dp){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = up + left;    
            }
        }
    }
    return dp[m - 1][n - 1];
}

// Space Optimized
int f4(int m, int n){
    vector<int> prev(n);

    for(int i = 0; i < m; i++){
        vector<int> temp(n);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) temp[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = temp[j - 1];
                temp[j] = up + left;    
            }
        }
        prev = temp;
    }
    return prev[n - 1];
}

int main(){
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << f4(m, n);
}