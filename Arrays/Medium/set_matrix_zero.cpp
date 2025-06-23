#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    // int col[m] = {0} -> matrix[0][..]
    // int row[n] = {0} -> matrix[..][0]
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                // mark the i-th row
                matrix[i][0] = 0;
                // mark the j-ht col
                if(j != 0){
                    matrix[0][j] == 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            // check for col and row
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j = 0; j < m; j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i < n; i++){
            matrix[i][0] = 0;
        }
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

   zeroMatrix(matrix, n, m);

   // output
    cout << "\nThe entered matrix is:\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}