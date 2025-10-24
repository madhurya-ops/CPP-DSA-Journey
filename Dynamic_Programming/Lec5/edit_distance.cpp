#include<iostream>
using namespace std;

// recursion
int f1(int i, int j, string S1, string S2){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(S1[i] == S2[j]) return 0 + f1(i - 1, j - 1, S1, S2);
        
    return min(
        1 + f1(i, j - 1, S1, S2),
        min(1 + f1(i - 1, j, S1, S2),
        1 + f1(i - 1, j - 1, S1, S2))
    );
}

// memiozation
int f2(int i, int j, string S1, string S2, vector<vector<int>> &dp){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(dp[i][j] != -1) return dp[i][j];

    if(S1[i] == S2[j]) return dp[i][j] = 0 + f2(i - 1, j - 1, S1, S2, dp);
        
    return dp[i][j] = min(
        1 + f2(i, j - 1, S1, S2, dp),
        min(1 + f2(i - 1, j, S1, S2, dp),
        1 + f2(i - 1, j - 1, S1, S2, dp))
    );
}

// tabulation
int f3(string S1, string S2) {
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 0; i <= n; i++) dp[i][0] = i;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(S1[i - 1] == S2[j - 1]) dp[i][j] = 0 + dp[i - 1][j - 1];
            else{
                dp[i][j] = min(
                    1 + dp[i][j - 1],
                    min(1 + dp[i - 1][j],
                    1 + dp[i - 1][j - 1])
                );
            }  
        }        
    }
    return dp[n][m];
}

// space optimization
int f4(string S1, string S2) {
    int n = S1.size();
    int m = S2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j <= m; j++){
            if(S1[i - 1] == S2[j - 1]) curr[j] = 0 + prev[j - 1];
            else{
                curr[j] = 1 + min(
                    curr[j - 1], min(prev[j], prev[j - 1])
                );
            }  
        }
        prev = curr;        
    }
    return prev[m];
}

int main(){
    string S1 = "horse";
    string S2 = "ros";

    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    // cout << f1(n - 1, m - 1, S1, S2);
    // cout << f2(n - 1, m - 1, S1, S2, dp);
    cout << f4(S1, S2);

}