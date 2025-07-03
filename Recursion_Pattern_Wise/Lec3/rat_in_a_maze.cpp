#include<iostream>
using namespace std;

void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> & ans, 
    string path, vector<vector<int>> &vis, int di[], int dj[]){
    
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        string dir = "DLRU";
        for(int ind = 0; ind < 4; ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && 
                !vis[nexti][nextj] && m[nexti][nextj] == 1){

                    vis[i][j] = 1;
                    solve(nexti, nextj, m, n, ans, path + dir[ind], vis, di, dj);
                    vis[i][j] = 0;
            }
        }
}

int main(){
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if(matrix[0][0] == 1) solve(0, 0, matrix, n, ans, "", vis, di, dj);
    
    for(auto it : ans){
        cout << it << " ";
        cout << endl;
    }

    return 0;
}