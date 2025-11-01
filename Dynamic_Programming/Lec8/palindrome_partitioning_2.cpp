#include<iostream>
using namespace std;

// check if the string is a palindrome or not
bool isPalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// recursion
int f1(int i, int n, string &s){
    if(i == n) return 0;
    int minCost = INT_MAX;

    for(int j = i; j < n; j++){
        if(isPalindrome(i, j, s)){
            int cost = 1 + f1(j + 1, n, s);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}

// memoization
int f2(int i, int n, string &s, vector<int> &dp){
    if(i == n) return 0;
    int minCost = INT_MAX;

    if(dp[i] != -1) return dp[i];

    for(int j = i; j < n; j++){
        if(isPalindrome(i, j, s)){
            int cost = 1 + f2(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

// tabulation
int f3(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
        int minCost = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

int main(){
    string s = "aab";
    int n = s.size();
    vector<int> dp(n, -1);
    
    // cout << f2(0, n, s, dp) - 1;
    cout << f3(s);
}