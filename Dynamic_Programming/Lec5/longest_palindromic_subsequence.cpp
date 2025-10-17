#include<iostream>
using namespace std;

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
    string s = "bbbab";
    string t = s;
    reverse(t.begin(), t.end());

    cout << f4(s, t);
}