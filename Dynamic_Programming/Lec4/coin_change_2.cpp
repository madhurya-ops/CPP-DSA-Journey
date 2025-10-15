#include<iostream>
using namespace std;

// recursion
int f1(int ind, int T, vector<int> &coins){
    if(ind == 0) return (T % coins[0] == 0);
    int notPick = f1(ind - 1, T, coins);
    int pick = 0;
    if(T >= coins[ind]) pick = f1(ind, T - coins[ind], coins);
    return pick + notPick; 
}

// memoizaiton
int f2(int ind, int T, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0) return (T % coins[0] == 0);

    if(dp[ind][T] != -1) return dp[ind][T];

    int notPick = f2(ind - 1, T, coins, dp);
    int pick = 0;
    if(T >= coins[ind]) pick = f2(ind, T - coins[ind], coins, dp);
    return dp[ind][T] = pick + notPick; 
}

// tabulation
int f3(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for(int T = 0; T <= amount; T++) dp[0][T] = (T % coins[0] == 0);

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= amount; T++){
            int notPick = dp[ind - 1][T];
            int pick = 0;
            if(T >= coins[ind]) pick = dp[ind][T - coins[ind]];
            dp[ind][T] = pick + notPick;
        }
    }
    return dp[n - 1][amount];
}

// space optimization
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<long> prev(amount + 1, 0), curr(amount + 1, 0);

    for(int T = 0; T <= amount; T++) prev[T] = (T % coins[0] == 0);

    for(int ind = 1; ind < n; ind++){
        for(int T = 0; T <= amount; T++){
            long long notPick = prev[T];
            long long pick = 0;
            if(T >= coins[ind]) pick = curr[T - coins[ind]];
            curr[T] = pick + notPick;
        }
        prev = curr;
    }
    return (int)prev[amount];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return f1(n - 1, amount, coins);
}

int main(){
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    cout << change(amount, coins);
}