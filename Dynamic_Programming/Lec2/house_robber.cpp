#include<iostream>
using namespace std;

// recursive approach
int func1(int ind, vector<int> &nums){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;

    int pick = nums[ind] + func1(ind - 2, nums);
    int notPick = 0 + func1(ind - 1, nums);

    return max(pick, notPick);
}

// memoized approach
int func2(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
        
    if(dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + func2(ind - 2, nums, dp);
    int notPick = 0 + func2(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick); 
}

// tabulation approach
int func3(vector<int> &nums, vector<int> &dp){
    int n = nums.size();
    dp[0] = nums[0];
    int neg = 0;

    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += dp[i - 2];
        int notTake = 0 + dp[i - 1];

        dp[i] = max(take, notTake);
    }

    return dp[n-1];
}

// space optimized approach
int rob(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = 0 + prev;

        int cur_i = max(take, notTake);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
} 

int main(){
    vector<int> nums = {1, 2, 3, 1};
    int n = nums.size();
    vector<int> dp(n, - 1);
    
    // cout << func3(nums, dp);
    cout << rob(nums);
}