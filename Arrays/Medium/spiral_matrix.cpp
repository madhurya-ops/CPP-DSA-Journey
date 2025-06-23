#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;
    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans; 
}

int main(){
    // input
    int n, m;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    // Declare a 2D vector (n rows, m columns)
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    spiralMatrix(matrix);


}