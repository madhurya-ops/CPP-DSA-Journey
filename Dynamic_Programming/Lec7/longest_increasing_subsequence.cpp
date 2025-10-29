#include<iostream>
using namespace std;

// recursion
int f1(int ind, int prevInd, vector<int> &nums){
        if(ind == nums.size()) return 0;

        int length = 0 + f1(ind + 1, prevInd, nums);
        if(prevInd == -1 || nums[ind] > nums[prevInd]) 
            length = max(length, 1 + f1(ind + 1, ind, nums));
        return length;
    }

// memoization
int f2(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;

        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];

        int length = 0 + f2(ind + 1, prevInd, nums, dp);
        if(prevInd == -1 || nums[ind] > nums[prevInd]) 
            length = max(length, 1 + f2(ind + 1, ind, nums, dp));
        return dp[ind][prevInd + 1] = length;
    }

// tabulation
int f3(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int ind = n - 1; ind >= 0; ind--){
            for(int prevInd = ind - 1; prevInd >= -1; prevInd--){
                int length = 0 + dp[ind + 1][prevInd + 1];
                if(prevInd == -1 || nums[ind] > nums[prevInd]) 
                    length = max(length, 1 + dp[ind + 1][ind + 1]);
                dp[ind][prevInd + 1] = length;
            }
        }

        return dp[0][-1 + 1];
    }

// space optimization
int f4(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--){
            for(int prevInd = ind - 1; prevInd >= -1; prevInd--){
                int length = 0 + next[prevInd + 1];
                if(prevInd == -1 || nums[ind] > nums[prevInd]){ 
                    length = max(length, 1 + next[ind + 1]);
                }
                curr[prevInd + 1] = length;
            }
            next = curr;
        }
        return next[-1 + 1];
    }

// 1-D space optimized
int f5(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }

// using a temp vector instead of maxi var and dp arr
int f6(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{   
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }

// binary search (O(nlogn))
int f7(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{   
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }

int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << f1(0, -1, nums);
}