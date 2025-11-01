#include<iostream>
using namespace std;

// recursion
int f1(int ind, int n, vector<int> &arr, int k){
    if(ind == n) return 0;

    int maxAns = INT_MIN;
    int maxi = INT_MIN;
    int len = 0;
    for(int j = ind; j < min(n, ind + k); j++){
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + f1(j + 1, n, arr, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}

// memoization
int f2(int ind, int n, vector<int> &arr, int k, vector<int> &dp){
    if(ind == n) return 0;

    if(dp[ind] != -1) return dp[ind];

    int maxAns = INT_MIN;
    int maxi = INT_MIN;
    int len = 0;
    for(int j = ind; j < min(n, ind + k); j++){
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + f2(j + 1, n, arr, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

// tabulation
int f3(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for(int ind = n - 1; ind >= 0; ind--){
        int maxAns = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int j = ind; j < min(n, ind + k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

int main(){
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    int n = arr.size();
    vector<int> dp(n, -1);

    cout << f1(0, n, arr, k);
}