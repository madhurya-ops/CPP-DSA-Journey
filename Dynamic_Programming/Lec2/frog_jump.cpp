#include<iostream>
using namespace std;

// Recursive solution
int func1(int n, vector<int> &heights){
    if(n == 0) return 0;
    int left = func1(n - 1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = func1(n - 2, heights) + abs(heights[n] - heights[n-2]);
    
    return min(left, right);
}

// Memoized solution
// TC -> O(N), SC -> O(2N)
int func2(int n, vector<int> &heights){
    if(n == 0) return 0;
    vector<int> dp(n+1, -1);
    if(dp[n] != -1) return dp[n];
    int left = func2(n - 1, heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = func2(n - 2, heights) + abs(heights[n] - heights[n-2]);

    return dp[n] = min(left, right);
}

// Tabulation solution 
// TC -> O(N), SC -> O(N) 
int func3(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int firstStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int secondStep = INT_MAX;
        if(i > 1) secondStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(firstStep, secondStep);
    }
    return dp[n-1];
} 

// Space Optimized Solution
// TC -> O(N), SC -> O(1)
int func4(int n, vector<int> &heights){
    int prev = 0, prev2 = 0;
    for(int i = 1; i < n; i++){
        int firstStep = prev + abs(heights[i] - heights[i - 1]);
        int secondStep = INT_MAX;
        if(i > 1) secondStep = prev2 + abs(heights[i] - heights[i - 2]);
        int cur_i = min(firstStep, secondStep);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int main(){
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    cout << func4(n - 1, heights);
}