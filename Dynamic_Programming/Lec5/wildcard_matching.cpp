#include<iostream>
using namespace std;

// recursion
bool f1(int i, int j, string &s, string &p){
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0){
        for(int ind = 0; ind <= j; ind++){
            if(p[ind] != '*') return false;
        }
        return true;
    }

    if(s[i] == p[j] || p[j] == '?') return f1(i - 1, j - 1, s, p);
    if(p[j] == '*') return f1(i - 1, j, s, p) | f1(i, j - 1, s, p);
    return false;
}

// memoization
bool f2(int i, int j, string &s, string &p, vector<vector<int>> &dp){
    if(i < 0 && j < 0) return true;
    if(j < 0 && i >= 0) return false;
    if(i < 0 && j >= 0){
        for(int ind = 0; ind <= j; ind++){
            if(p[ind] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == p[j] || p[j] == '?') return dp[i][j] = f2(i - 1, j - 1, s, p, dp);
    if(p[j] == '*') return dp[i][j] = f2(i - 1, j, s, p, dp) | f2(i, j - 1, s, p, dp);
    return dp[i][j] = false;
}

// tabulation
bool f3(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;
    for(int i = 1; i <= n; i++) dp[i][0] = false;
    for(int j = 1; j <= m; j++){
        bool fl = true;
        for(int ind = 1; ind <= j; ind++){
            if(p[ind - 1] != '*'){
                fl = false;
                break;
            }
        }
        dp[0][j] = fl;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// space optimization
bool f4(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    prev[0] = true;

    for (int j = 1; j <= m; j++) {
        bool fl = true;
        for (int ind = 1; ind <= j; ind++) {
            if (p[ind - 1] != '*') {
                fl = false;
                break;
            }
        }
        prev[j] = fl;
    }

    // fill dp
    for (int i = 1; i <= n; i++) {
        curr[0] = false;
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if (p[j - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}

int main(){
    string s = "aa";
    string p = "*";

    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // cout << f1(n - 1, m -  1, s, p);
    // cout << f2(n - 1, m -  1, s, p, dp);
    cout << f4(s, p);
}