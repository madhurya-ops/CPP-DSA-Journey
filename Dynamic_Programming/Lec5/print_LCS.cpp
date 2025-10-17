#include<iostream>
using namespace std;

// tabulation
string f3(string S1, string S2) {
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

    // declaring the LCS 
    int len = dp[n][m];
    string ans = "";
    for(int i = 0; i < len; i++){
        ans += "$"; // filling with dummy val
    }

    int ind = len - 1;
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(S1[i - 1] == S2[j - 1]){
            ans[ind] = S1[i - 1];
            ind--;
            // when the char matches, move diagonally up in the left direction
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    return ans;
}

int main(){
    string S1 = "abcde";
    string S2 = "ace";

    cout << f3(S1, S2);
}