#include<iostream>
using namespace std;

// recursion
int f1(int ind, int buy, int cap, vector<int> &prices){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;

        if(buy){
            return max(
                -prices[ind] + f1(ind + 1, 0, cap, prices),
                0 + f1(ind + 1, 1, cap, prices)
            );
        }
        else{
            return max(
                prices[ind] + f1(ind + 1, 1, cap - 1, prices),
                0 + f1(ind + 1, 0, cap, prices)
            );
        }
    }

// memoization
int f2(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap]; 

        if(buy){
            return dp[ind][buy][cap] = max(
                -prices[ind] + f2(ind + 1, 0, cap, prices, dp),
                0 + f2(ind + 1, 1, cap, prices, dp)
            );
        }
        else{
            return dp[ind][buy][cap] = max(
                prices[ind] + f2(ind + 1, 1, cap - 1, prices, dp),
                0 + f2(ind + 1, 0, cap, prices, dp)
            );
        }
    }

// tabulation
int f3(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy){
                        dp[ind][buy][cap] = max(
                            -prices[ind] + dp[ind + 1][0] [cap],
                            0 + dp[ind + 1][1][cap]
                        );
                    }
                    else{
                        dp[ind][buy][cap] = max(
                            prices[ind] + dp[ind + 1][1][cap - 1],
                            0 + dp[ind + 1][0][cap]
                        );
                    }
                }
            }
        }
        return dp[0][1][2];
    }

// space optimized
int f4(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy){
                        curr[buy][cap] = max(
                            -prices[ind] + after[0] [cap],
                            0 + after[1][cap]
                        );
                    }
                    else{
                        curr[buy][cap] = max(
                            prices[ind] + after[1][cap - 1],
                            0 + after[0][cap]
                        );
                    }
                }
            }
            after = curr;
        }
        return after[1][2];
    }

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << f4(prices);
}