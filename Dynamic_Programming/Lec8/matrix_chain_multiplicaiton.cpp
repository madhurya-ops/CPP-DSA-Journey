#include<iostream>
using namespace std;

// recurison
int f1(int i, int j, vector<int> &arr){
    if(i == j) return 0;

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + f1(i, k, arr) + f1(k + 1, j, arr);
        if(steps < mini){
            mini = steps;
        } 
    }
    return mini;
}

// memoization
int f2(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + f2(i, k, arr, dp) + f2(k + 1, j, arr, dp);
        if(steps < mini){
            mini = steps;
        } 
    }
    return dp[i][j] = mini;
}

// tabulation
int f3(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            int mini = 1e9;
            for(int k = i; k < j; k++){
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if(steps < mini){
                    mini = steps;
                } 
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << f3(arr);
}