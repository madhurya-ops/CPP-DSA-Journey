#include<iostream>
using namespace std;

// recursion
int f1(int ind, int target, vector<int> &prices){
    if(ind == 0){
        return (target * prices[0]);
    }
    int notTake = 0 + f1(ind - 1, target, prices);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if(rodLength <= target) take = prices[ind] + f1(ind, target - rodLength, prices);
    return max(take, notTake);
}

// memoization
int f2(int ind, int target, vector<int> &prices, vector<vector<int>> &dp){
    if(ind == 0){
        return (target * prices[0]);
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int notTake = 0 + f2(ind - 1, target, prices, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if(rodLength <= target) take = prices[ind] + f2(ind, target - rodLength, prices, dp);
    return dp[ind][target] = max(take, notTake);
}

// tabulation
int f3(int target, vector<int> &prices){
    vector<vector<int>> dp(target, vector<int>(target + 1, 0));

    for(int N = 0; N <= target; N++){
        dp[0][N] = N * prices[0];
    }

    for(int ind = 1; ind < target; ind++){
        for(int N = 0; N <= target; N++){
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= N) take = prices[ind] + dp[ind][N - rodLength];
            dp[ind][N] = max(take, notTake);
        }
    }
    return dp[target - 1][target];
}

// space optimization (2-array)
int f4(int target, vector<int> &prices){
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    for(int N = 0; N <= target; N++){
        prev[N] = N * prices[0];
    }

    for(int ind = 1; ind < target; ind++){
        for(int N = 0; N <= target; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= N) take = prices[ind] + curr[N - rodLength];
            curr[N] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[target];
}

// space optimization (1-array)
int f5(int target, vector<int> &prices){
    vector<int> prev(target + 1, 0);

    for(int N = 0; N <= target; N++){
        prev[N] = N * prices[0];
    }

    for(int ind = 1; ind < target; ind++){
        for(int N = 0; N <= target; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= N) take = prices[ind] + prev[N - rodLength];
            prev[N] = max(take, notTake);
        }
    }
    return prev[target];
}

int main(){
    vector<int> prices = {2, 5, 7, 8, 10};
    int target = prices.size();
    vector<vector<int>> dp(target, vector<int>(target + 1, -1));

    // cout << f1(target - 1, target, prices);
    // cout << f2(target - 1, target, prices, dp);
    cout << f5(target, prices);
}