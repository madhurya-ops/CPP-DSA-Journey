#include<iostream>
using namespace std;

// recursion
int f1(int i, int j, vector<int> &nums){
    if(i > j) return 0;
    int maxi = -1e9;
        
    for(int ind = i; ind <= j; ind++){
        int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + f1(i, ind - 1, nums) + f1(ind + 1, j, nums);
        maxi = max(maxi, cost);
    }
    return maxi;
}

// memoization
int f2(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
    if(i > j) return 0;
    int maxi = -1e9;

    if(dp[i][j] != -1) return dp[i][j];
        
    for(int ind = i; ind <= j; ind++){
        int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + f2(i, ind - 1, nums, dp) + f2(ind + 1, j, nums, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

// tabulation
int f3(vector<int>& nums) {
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n; j++){
            if(i > j) continue;

            int maxi = -1e9;
            for(int ind = i; ind <= j; ind++){
                int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

int main(){
    vector<int> nums = {3, 1, 5, 8};
    int n = nums.size();
    /*
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    */
    

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << f3(nums);
}