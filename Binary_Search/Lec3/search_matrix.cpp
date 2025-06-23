#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// BS applied using the principle of elimination
bool SearchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;
    while(row < n && col >= 0){
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

//whole matrix sorted
bool searchMatrix(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = m*n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int row = mid / 2;
        int col = mid % 2;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main(){
    // input
    int n;
    cout << "Enter the no. of rows: ";
    cin >> n;
    int m;
    cout << "Enter the no. of cols: ";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter the value of target: ";
    cin >> target;

    cout << searchMatrix(matrix, target);

}