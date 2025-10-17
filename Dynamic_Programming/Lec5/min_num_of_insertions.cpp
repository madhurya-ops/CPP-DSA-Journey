#include<iostream>
using namespace std;

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

int longestPalindromicSubsequence(string s){
    string t = s;
    reverse(t.begin(), t.end());

    return f4(s, t);
}

int main(){
    string s = "leetcode";

    cout << s.size() - longestPalindromicSubsequence(s);
}