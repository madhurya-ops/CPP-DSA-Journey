#include<iostream>
using namespace std;

// recursion
int f1(int ind1, int ind2, string S1, string S2){
    if(ind1 < 0 || ind2 < 0) return 0;
    if(S1[ind1] == S2[ind2]) return 1 + f1(ind1 - 1, ind2 - 1, S1, S2);
    return max(f1(ind1 - 1, ind2, S1, S2), f1(ind1, ind2 - 1, S1, S2));
}

// memoization
int f2(int ind1, int ind2, string S1, string S2, vector<vector<int>> &dp){
    if(ind1 < 0 || ind2 < 0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(S1[ind1] == S2[ind2]) return dp[ind1][ind2] = 1 + f2(ind1 - 1, ind2 - 1, S1, S2, dp);
    return dp[ind1][ind2] = max(f2(ind1 - 1, ind2, S1, S2, dp), f2(ind1, ind2 - 1, S1, S2, dp));
}

// tabulation
int f3(string S1, string S2) {
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(S1[i - 1] == S2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    } 
    return dp[n][m];
}

// space optimized
int f4(string S1, string S2) {
    int n = S1.size();
    int m = S2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    
    for(int j = 0; j <= m; j++) prev[j] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(S1[i - 1] == S2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }
            else curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    } 
    return prev[m];
}

int main(){
    string S1 = "abcde";
    string S2 = "ace";

    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // cout << f1(n - 1, m - 1, S1, S2);
    // cout << f2(n - 1, m - 1, S1, S2, dp);
    cout << f4(S1, S2);
}