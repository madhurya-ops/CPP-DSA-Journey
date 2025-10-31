#include<iostream>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;

    for(int i = 0; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]){
                dp[i] = 1 + dp[prev];
                // inherit the count
                cnt[i] = cnt[prev];
            }
            else if(nums[prev] < nums[i] && 1 + dp[prev] == dp[i]){
                // increase the count
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);      
    }
    int nos = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxi) nos += cnt[i];
    }
    return nos;
}

int main(){
    vector<int> nums = {2,2,2,2,2};

    cout << findNumberOfLIS(nums);
}