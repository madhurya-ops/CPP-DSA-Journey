#include<iostream>
using namespace std;

// recursion
int f1(int i, int j, vector<int> & cuts){
    if(i > j) return 0;

    int mini = 1e9;
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j + 1] - cuts[i - 1] + f1(i, ind - 1, cuts) + f1(ind + 1, j, cuts);
        mini = min(mini, cost);  
    }
    return mini;
}

// memoization
int f2(int i, int j, vector<int> & cuts, vector<vector<int>> &dp){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int ind = i; ind <= j; ind++){
        int cost = cuts[j + 1] - cuts[i - 1] + f2(i, ind - 1, cuts, dp) + f2(ind + 1, j, cuts, dp);
        mini = min(mini, cost);  
    }
    return dp[i][j] = mini;
}

// tabulation
int f3(int n, vector<int>& cuts) {
    int sz = cuts.size();
    vector<vector<int>> dp(sz + 2, vector<int>(sz + 2, 0));
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    for(int i = sz; i >= 1; i--){
        for(int j = 1; j <= sz; j++){
            if(i > j) continue;

            int mini = 1e9;
            for(int ind = i; ind <= j; ind++){
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, cost);  
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][sz];
}

int main(){
    vector<int> cuts = {1, 3, 4, 5};
    int n = 7;
    /*
    int sz = cuts.size();
    vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, -1));
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    */
    

    cout << f3(n, cuts);
}