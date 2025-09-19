#include<iostream>
using namespace std;

void shortestDist(vector<vector<int>> &matrix){
    int n = matrix.size();
    // traverse in the matrix set the diagonals to 0
    // set -1 to 1e9
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            if(i == j) matrix[i][j] = 0;
        }
    }

    // set the new path weights if newWt < oldWt
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){  
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // to detect a negative cycle in the graph
    // instead of continue, return a null or something 
    for(int i = 0; i < n; i++){
        if(matrix[i][i] < 0){
            continue;
        }
    }

    // before returning the matrix, set 1e9 to -1 again
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {0, 1, 43},
        {1, 0, 6},
        {-1, -1, 0}
    };
    shortestDist(matrix);
    for(auto comp : matrix){
        for(auto it : comp){
            cout << it << " ";
        }
        cout << endl;
    }
}