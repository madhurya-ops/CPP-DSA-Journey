#include<iostream>
using namespace std;

// recursion
int f1(int ind, int sum, vector<int> &arr){
    if(sum == 0) return 1;
    if(ind == 0) return (sum == arr[ind]);

    int notPick = f1(ind - 1, sum, arr);
    int pick = 0;
    if(arr[ind] <= sum) pick = f1(ind - 1, sum - arr[ind], arr);
    return pick + notPick;
}

// memoization
int f2(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }

    if(dp[ind][sum] != -1) return dp[ind][sum];

    int notPick = f1(ind - 1, sum, arr);
    int pick = 0;
    if(arr[ind] <= sum) pick = f1(ind - 1, sum - arr[ind], arr);
    return dp[ind][sum] = pick + notPick;
}

// tabulation
int f3(int target, vector<int> &arr, vector<vector<int>> &dp){
    int n = arr.size();
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(arr[0] <= target) dp[0][arr[0]] = 1;

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
    prev[0] = curr[0] = 1;
    if(arr[0] <= target) prev[arr[0]] = 1;

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

int main(){
    vector<int> arr = {1, 2, 2, 3};
    int n = arr.size();
    int sum = 3;
    // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    // cout << f1(n - 1, sum, arr);
    // cout << f2(n-1, sum, arr, dp);
    // cout << f3(sum, arr, dp);
    cout << f4(sum, arr);
}