#include<iostream>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, 
    vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
        // base condition
        if(col == n){
            ans.push_back(board);
            return;
        }

        // checking and placing the queen in a row
        for(int row = 0; row < n; row++){
            // check if queen is safe to be placed
            // upper diagonal = row + col
            // lower diagonal = n-1 + col - row
            if(leftRow[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1 + col - row] == 0){
                board[row][col] = 'Q'; // placing the queen
                leftRow[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1 + col - row] = 1;
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // moving to another col
                board[row][col] = '.'; // rolling back the changes made on the board, once a board is returned
                leftRow[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1 + col - row] = 0;
            }
        }
    }


int main(){
    int n = 4;
    vector<vector<string>> ans;
    // creating a ds which stores the locations of the queens placed
    vector<string> board(n);
    string s(n, '.');
    for(int i = 0; i < n; i++){
        board[i] = s;
    }
    vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    
    for(auto comb : ans){
        for(auto it : comb){
            cout << it << ',' << " ";
        }
        cout << endl;
    }
    return 0;
}