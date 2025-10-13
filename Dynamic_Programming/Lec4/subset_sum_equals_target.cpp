#include<iostream>
using namespace std;

// recursion
bool f1(int ind, int target, vector<int> &arr){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);

    bool notTake = f1(ind - 1, target, arr);
    bool take = false;
    if(target >= arr[ind]) take = f1(ind - 1, target - arr[ind], arr);

    return notTake || take;
}

// memoization
bool f2(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = f1(ind - 1, target, arr);
    bool take = false;
    if(target >= arr[ind]) take = f1(ind - 1, target - arr[ind], arr);

    return dp[ind][target] = notTake || take;
}

// tabulation
bool f3(int k, vector<int> &arr, vector<vector<bool>> &dp){
    int n = arr.size();
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++){
        for(int target = 0; target <= k; target++){
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (target >= arr[i]) take = dp[i - 1][target - arr[i]];

            dp[i][target] = notTake || take;
        }
    }
    return dp[n - 1][k];
}

// space optimized
bool f4(int k, vector<int> &arr, vector<vector<bool>> &dp){
    int n = arr.size();
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true; 

    for(int i = 1; i < n; i++){
        for(int target = 0; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[i]) take = prev[target - arr[i]];

            curr[target] = notTake || take;
        }
        prev = curr;
    }
    return prev[k];
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    int k = 2;

    // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    cout << f4(k, arr, dp);
}