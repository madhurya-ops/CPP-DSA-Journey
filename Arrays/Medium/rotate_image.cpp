#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>> &matrix){
    int n = matrix.size();
    // transpose
    // O(N / 2 * N / 2)
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse the rows
    // O(N * N / 2)
    for(int i = 0; i < n; i++){
        // row is matrix[i]
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
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

   rotateImage(matrix);

   // output
    cout << "\nThe entered matrix is:\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}