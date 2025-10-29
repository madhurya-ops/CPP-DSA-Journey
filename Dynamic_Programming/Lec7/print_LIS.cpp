#include<iostream>
using namespace std;

vector<int> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 1;

        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

int main(){
    vector<int> nums = {5, 4, 11, 1, 16, 8};
    vector<int> ans = lengthOfLIS(nums);

    for(auto it : ans){
        cout << it << " ";
    }
}