#include<iostream>
using namespace std;

// recursion
int f1(int ind, int W, vector<int> &weights, vector<int> &values){
    if(ind == 0){
        return ((W / weights[0]) * values[0]);
    }
    int notTake = 0 + f1(ind - 1, W, weights, values);
    int take = INT_MIN;
    if(W >= weights[ind]) take = values[ind] + f1(ind, W - weights[ind], weights, values);
    return max(take, notTake);
}

// memoization
int f2(int ind, int W, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp){
    if(ind == 0){
        return ((W / weights[0]) * values[0]);
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = 0 + f2(ind - 1, W, weights, values, dp);
    int take = INT_MIN;
    if(W >= weights[ind]) take = values[ind] + f2(ind, W - weights[ind], weights, values, dp);
    return dp[ind][W] = max(take, notTake);
}

// tabulation
int f3(int W, vector<int> &weights, vector<int> &values, vector<vector<int>> &dp){
    int n = weights.size();
    for(int wt = 0; wt <= W; wt++){
        dp[0][wt] = ((wt / weights[0]) * values[0]);
    }
    for(int ind = 1; ind < n; ind++){
        for(int j = 0; j <= W; j++){
            int notTake = 0 + dp[ind - 1][j];
            int take = INT_MIN;
            if (j >= weights[ind]) take = values[ind] + dp[ind][j - weights[ind]];
            dp[ind][j] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}

// space optimized (2-array optimization)
int f4(int W, vector<int> &weights, vector<int> &values){
    int n = weights.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for(int wt = 0; wt <= W; wt++){
        prev[wt] = ((wt / weights[0]) * values[0]);
    }
    for(int ind = 1; ind < n; ind++){
        for(int j = 0; j <= W; j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if (j >= weights[ind]) take = values[ind] + curr[j - weights[ind]];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}

// space optimization(1-array optimization)
int f5(int W, vector<int> &weights, vector<int> &values){
    int n = weights.size();
    vector<int> prev(W + 1, 0);

    for(int wt = 0; wt <= W; wt++){
        prev[wt] = ((wt / weights[0]) * values[0]);
    }
    for(int ind = 1; ind < n; ind++){
        for(int j = 0; j <= W; j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if (j >= weights[ind]) take = values[ind] + prev[j - weights[ind]];
            prev[j] = max(take, notTake);
        }
    }
    return prev[W];
}

int main(){
    vector<int> weights = {2, 4, 6};
    vector<int> values = {5, 11, 13};
    int bagWt = 10;
    int n = weights.size();

    // vector<vector<int>> dp(n, vector<int>(bagWt + 1, -1));
    vector<vector<int>> dp(n, vector<int>(bagWt + 1, 0));

    // cout << f1(n - 1, bagWt, weights, values);
    // cout << f2(n - 1, bagWt, weights, values, dp);
    // cout << f3(bagWt, weights, values, dp);
    cout << f5(bagWt, weights, values);
}