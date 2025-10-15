#include<iostream>
#include <numeric>
using namespace std;

// recursion
int f1(int ind, int sum, vector<int> &arr){
    if (ind == 0) {
        if (sum == 0 && arr[0] == 0) return 2;
        if (sum == 0 || sum == arr[0]) return 1;
        return 0;
    }

    int notPick = f1(ind - 1, sum, arr);
    int pick = 0;
    if(arr[ind] <= sum) pick = f1(ind - 1, sum - arr[ind], arr);
    return pick + notPick;
}

// Memoization
int f2(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (ind == 0) {
        if (sum == 0 && arr[0] == 0) return 2;
        if (sum == 0 || sum == arr[0]) return 1;
        return 0;
    }

    if (dp[ind][sum] != -1) return dp[ind][sum];

    int notPick = f2(ind - 1, sum, arr, dp);
    int pick = 0;
    if (arr[ind] <= sum) pick = f2(ind - 1, sum - arr[ind], arr, dp);

    return dp[ind][sum] = pick + notPick;
}

// tabulation
int f3(int target, vector<int> &arr, vector<vector<int>> &dp){
    int n = arr.size();
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= target; sum++){
            int notPick = dp[ind - 1][sum];
            int pick = 0;
            if(arr[ind] <= sum) pick = dp[ind - 1][sum - arr[ind]];
            dp[ind][sum] = pick + notPick;
        }
    }
    return dp[n - 1][target];
}

// space optimization
int f4(int target, vector<int> &arr){
    int n = arr.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= target; sum++){
            int notPick = prev[sum];
            int pick = 0;
            if(arr[ind] <= sum) pick = prev[sum - arr[ind]];
            curr[sum] = pick + notPick;
        }
        prev = curr;
    }
    return prev[target];
}

int countPartitions(int d, vector<int> &arr, vector<vector<int>> &dp) {
    int n = arr.size();
    int totSum = 0;
    for (int i = 0; i < n; i++) totSum += arr[i];

    if (totSum - d < 0 || (totSum - d) % 2) return 0;

    int target = (totSum - d) / 2;
    // return f2(n - 1, target, arr, dp);
    return f4(target, arr);
}

int main() {
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    int target = (totSum - d) / 2;

    // vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, 0));
    cout << countPartitions(d, arr, dp);
}