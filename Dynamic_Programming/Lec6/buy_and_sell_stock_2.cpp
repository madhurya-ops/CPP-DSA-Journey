#include<iostream>
using namespace std;

// recursion
int f1(int ind, int buy, vector<int>& prices){
    if(ind == prices.size()) return 0;
    int profit = 0;

    if(buy){
        profit = max(
            -prices[ind] + f1(ind + 1, 0, prices), 
            0 + f1(ind + 1, 1, prices)
        ); 
    }
    else{
        profit = max(
            prices[ind] + f1(ind + 1, 1, prices),
            0 + f1(ind + 1, 0, prices)
        );
    }
    return profit;
}

// memoization
int f2(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
    if(ind == prices.size()) return 0;
    int profit = 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy){
        profit = max(
            -prices[ind] + f2(ind + 1, 0, prices, dp), 
            0 + f2(ind + 1, 1, prices, dp)
        ); 
    }
    else{
        profit = max(
            prices[ind] + f2(ind + 1, 1, prices, dp),
            0 + f2(ind + 1, 0, prices, dp)
        );
    }
    return dp[ind][buy] = profit;
}

// tabulation
int f3(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;

    int profit = 0;
    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            if(buy){
                profit = max(
                    -prices[ind] + dp[ind + 1][0], 
                    0 + dp[ind + 1][1]
                ); 
            }
            else{
                profit = max(
                    prices[ind] + dp[ind + 1][1],
                    0 + dp[ind + 1][0]
                );
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// space optimized
int f4(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;

    int profit = 0;
    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            if(buy){
                profit = max(
                    -prices[ind] + ahead[0], 
                    0 + ahead[1]
                ); 
            }
            else{
                profit = max(
                    prices[ind] + ahead[1],
                    0 + ahead[0]
                );
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return curr[1];
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout << f4(prices);
}