#include<iostream>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image,
    int newColor, int delRow[], int delCol[], int iniColor){
        int n = image.size();
        int m = image[0].size();

        // set the starting node to the new color
        ans[row][col] = newColor;

        // traverse the neighbouring node with the same initial color
        // change them to new color
        for(int i = 0; i < 4; i++){
            // checking for all the four neighbours
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor){
                    dfs(nRow, nCol, ans, image, newColor, delRow, delCol, iniColor);
            }
        }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int iniColor = image[sr][sc]; // store the initial color
    vector<vector<int>> ans = image; // make a copy of the given matrix
    // directions to trverse: top, right, bottom and left
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