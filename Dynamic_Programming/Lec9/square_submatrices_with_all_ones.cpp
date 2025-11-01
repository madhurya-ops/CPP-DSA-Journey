#include<iostream>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> maximalSquare(m+1, vector<int>(n+1, 0));
    int squareSubmatrices = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i-1][j-1] == 1){
                maximalSquare[i][j] = 1 + min({maximalSquare[i-1][j], maximalSquare[i][j-1], maximalSquare[i-1][j-1]});
                squareSubmatrices += maximalSquare[i][j];
            }
        }
    }
    return squareSubmatrices;
}

int main(){
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    cout << countSquares(matrix);
}