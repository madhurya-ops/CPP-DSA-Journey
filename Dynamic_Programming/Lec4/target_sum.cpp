#include<iostream>
using namespace std;

int f3(int target, vector<int> &arr, vector<vector<int>> &dp) {
    int n = arr.size();
    if (arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= target; sum++) {
            int notPick = dp[ind - 1][sum];
            int pick = 0;
            if (arr[ind] <= sum)
                pick = dp[ind - 1][sum - arr[ind]];
            dp[ind][sum] = pick + notPick;
        }
    }
    return dp[n - 1][target];
}

int countPartitions(int d, vector<int> &arr) {
    int n = arr.size();
    int totSum = 0;
    for (int i = 0; i < n; i++) totSum += arr[i];

    if (totSum - d < 0 || (totSum - d) % 2) return 0;

    int target = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    return f3(target, arr, dp);
}


int main(){
    int target = 3;
    vector<int> nums = {1,1,1,1,1};

    cout << countPartitions(target, nums);
}