#include<iostream>
using namespace std;

// recursion
int f1(int ind, int W, vector<int> &weights, vector<int> &values){
    if(ind == 0){
        if(weights[0] <= W) return values[0];
        else return 0;
    }
    int notTake = 0 + f1(ind - 1, W, weights, values);
    int take = INT_MIN;
    if(weights[ind] <= W){
        take = values[ind] + f1(ind - 1, W - weights[ind], weights, values);
    }
    return max(take, notTake);
}

// memoization
int f2(int ind, int W, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp){
    if(ind == 0){
        if(weights[0] <= W) return values[0];
        else return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = 0 + f2(ind - 1, W, weights, values, dp);
    int take = INT_MIN;
    if(weights[ind] <= W){
        take = values[ind] + f2(ind - 1, W - weights[ind], weights, values, dp);
    }
    return dp[ind][W] = max(take, notTake);
}

// Tablulation
int f3(int W, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp){
    int n = weights.size();
    for(int i = weights[0]; i <= W; i++) dp[0][i] = values[0];

    for(int ind = 1; ind < n; ind++){
        for(int j = 0; j <= W; j++){
            int notTake = 0 + dp[ind - 1][j];
            int take = INT_MIN;
            if(weights[ind] <= j){
                take = values[ind] + dp[ind - 1][j - weights[ind]];
            }
            dp[ind][j] = max(take, notTake);
        } 
    }
    return dp[n - 1][W];
}

// Space optimization
int f4(int W, vector<int> &weights, vector<int> &values){
    int n = weights.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for(int i = weights[0]; i <= W; i++) prev[i] = values[0];

    for(int ind = 1; ind < n; ind++){
        for(int j = 0; j <= W; j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(weights[ind] <= j){
                take = values[ind] + prev[j - weights[ind]];
            }
            curr[j] = max(take, notTake);
        } 
        prev = curr;
    }
    return prev[W];
}

// better space optimized (using only single row)
int f5(int W, vector<int> &weights, vector<int> &values){
    int n = weights.size();
    vector<int> prev(W + 1, 0);

    for(int i = weights[0]; i <= W; i++) prev[i] = values[0];

    for(int ind = 1; ind < n; ind++){
        for(int j = W; j >= 0; j--){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(weights[ind] <= j){
                take = values[ind] + prev[j - weights[ind]];
            }
            prev[j] = max(take, notTake);
        }
    }
    return prev[W];
}

int main(){
    vector<int> weights = {3, 4, 5};
    vector<int> values = {30, 50, 60};
    int n = weights.size();
    int bagWt = 8;
    // vector<vector<int>> dp(n, vector<int>(bagWt + 1, -1));
    vector<vector<int>> dp(n, vector<int>(bagWt + 1, 0));
    // cout << f1(n - 1, bagWt, weights, values);
    // cout << f2(n - 1, bagWt, weights, values, dp);
    // cout << f3(bagWt, weights, values, dp);
    // cout << f4(bagWt, weights, values);
    cout << f5(bagWt, weights, values);
}