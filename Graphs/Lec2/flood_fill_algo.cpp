#include<iostream>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
    int newColor, int delRow[], int delCol[], int iniColor){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor){
                    dfs(nRow, nCol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, color, delRow, delCol, iniColor);
    return ans;
}

int main(){
    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    for(auto comp : ans){
        for(auto it : comp){
            cout << it << " ";
        }
        cout << endl;
    }
}