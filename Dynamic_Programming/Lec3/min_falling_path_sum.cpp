#include<iostream>
using namespace std;

// recursion
int f1(int i, int j, int n, int m, vector<vector<int>> &mat){
    if(j < 0 || j >= m) return 1e9;
    if(i == 0) return mat[0][j];

    int s = mat[i][j] + f1(i - 1, j, n, m, mat);
    int ld = mat[i][j] + f1(i - 1, j - 1, n, m, mat);
    int rd = mat[i][j] + f1(i - 1, j + 1, n, m, mat);

    return min(s, min(ld, rd));
}

// memoization
int f2(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(j < 0 || j >= m) return 1e9;
    if(i == 0) return mat[0][j];

    if(dp[i][j] != -1) return dp[i][j];

    int s = mat[i][j] + f1(i - 1, j, n, m, mat);
    int ld = mat[i][j] + f1(i - 1, j - 1, n, m, mat);
    int rd = mat[i][j] + f1(i - 1, j + 1, n, m, mat);

    return dp[i][j] = min(s, min(ld, rd));
}

int f3(vector<vector<int>> &mat, vector<vector<int>> &dp){
    int n = mat.size();
    int m = mat[0].size();

    for(int j = 0; j < m; j++){
        dp[0][j] = mat[0][j];
    }

    for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int straight = mat[i][j] + dp[i - 1][j];

                int leftDiag = mat[i][j];
                if(j - 1 >= 0) leftDiag += dp[i - 1][j - 1];
                else leftDiag += 1e9;

                int rightDiag = mat[i][j];
                if(j + 1 < m) rightDiag += dp[i - 1][j + 1];
                else rightDiag += 1e9;

                dp[i][j] = min({straight, leftDiag, rightDiag});
            }
        }

        int minn = dp[n - 1][0];
        for(int ind = 1; ind < m; ind++){
            minn = min(minn, dp[n - 1][ind]);
        }
        
        return minn;
}

// space optimized
int f4(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m);
    for(int j = 0; j < m; j++){
        prev[j] = matrix[0][j];
    }

    for(int i = 1; i < n; i++){
        vector<int> curr(m);
        for(int j = 0; j < m; j++){
            int straight = matrix[i][j] + prev[j];

            int leftDiag = matrix[i][j];
            if(j - 1 >= 0) leftDiag += prev[j - 1];
            else leftDiag += 1e9;

            int rightDiag = matrix[i][j];
            if(j + 1 < m) rightDiag += prev[j + 1];
            else rightDiag += 1e9;

            curr[j] = min({straight, leftDiag, rightDiag});
        }
        prev = curr;
    }

    int minn = prev[0];
    for(int ind = 0; ind < m; ind++){
        minn = min(minn, prev[ind]);
    } 
    return minn;
}

int main(){
    vector<vector<int>> mat = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    // int minn = 1e9;
    // for (int j = 0; j < m; j++) {
    //     minn = min(minn, f1(n - 1, j, n, m, mat));
    // }

    // int minn = 1e9;
    // for (int j = 0; j < m; j++) {
    //     minn = min(minn, f2(n - 1, j, n, m, mat, dp));
    // }
    // cout << minn

    // cout << f3(mat, dp);
    cout << f4(mat);
}