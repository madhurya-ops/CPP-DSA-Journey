#include<iostream>
using namespace std;

// recursion
int f1(int ind, int T, vector<int> &coins){
    if(ind == 0){
        if(T % coins[0] == 0) return T / coins[0];
        else return 1e9;
    }
    int notPick = 0 + f1(ind - 1, T, coins);
    int pick = 1e9;
    if(T >= coins[ind]){
        pick = 1 + f1(ind, T - coins[ind], coins);
    }
    return min(pick, notPick);
}

// memoization
int f2(int ind, int T, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        if(T % coins[0] == 0) return T / coins[0];
        else return 1e9;
    }

    if(dp[ind][T] != -1) return dp[ind][T];

    int notPick = 0 + f2(ind - 1, T, coins, dp);
    int pick = 1e9;
    if(T >= coins[ind]){
        pick = 1 + f2(ind, T - coins[ind], coins, dp);
    }
    return dp[ind][T] = min(pick, notPick);
}

// tabulation
int f3(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for(int T = 0; T <= amount; T++){
        if(T % coins[0] == 0){
            dp[0][T] = T / coins[0];
        }
        else{
            dp[0][T] = 1e9;
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= amount; T++){
            int notPick = 0 + dp[ind - 1][T];
            int pick = 1e9;
            if(T >= coins[ind]){
                pick = 1 + dp[ind][T - coins[ind]];
            }
            dp[ind][T] = min(pick, notPick);
        }
    }

    int ans = dp[n - 1][amount];

    if(ans >= 1e9) return -1;
    return ans;
}

// space optimized
int f4(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for(int T = 0; T <= amount; T++){
        if(T % coins[0] == 0){
            prev[T] = T / coins[0];
        }
        else{
            prev[T] = 1e9;
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= amount; T++){
            int notPick = 0 + prev[T];
            int pick = 1e9;
            if(T >= coins[ind]){
                pick = 1 + curr[T - coins[ind]];
            }
            curr[T] = min(pick, notPick);
        }
        prev = curr;
    }

    int ans = prev[amount];

    if(ans >= 1e9) return -1;
    return ans;
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f2(n - 1, amount, coins, dp);

    if(ans >= 1e9) return -1;
    return ans;
}

int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    // cout << coinChange(coins, amount);
    cout << f4(coins, amount);
}