#include<iostream>
using namespace std;

int fibo(int n, vector<int> &dp){
    // base case
    if(n <= 1) return n;

    // use the precomputed val (avoid redundant calculations)
    if(dp[n] != -1) return dp[n];

    // store the val of new calc in the arr 
    // so that it can fetched later
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

int fibo2(int n){
    int prev = 1;
    int prev2 = 0;
    for(int i = 2; i <= n; i++){
        int cur_i = prev + prev2;
        prev2 = prev;
        prev = cur_i; 
    }
    return prev;
}

int main(){
    int n = 4;
    vector<int> dp(n + 1, -1);
    // cout << fibo(n, dp);
    cout << fibo2(n);
}