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
        
    string ans = "";
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(S1[i - 1] == S2[j - 1]){
            ans += S1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            ans += S1[i - 1];
            i--;
        }
        else{
            ans += S2[j - 1];
            j--;
        }
    }

    while(i > 0){
        ans += S1[i - 1];
        i--;
    }

    while(j > 0){
        ans += S2[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string S1 = "abac";
    string S2 = "cab";

    cout << f3(S1, S2);
}