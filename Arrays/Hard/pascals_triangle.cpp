#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
// given row and col, find the element at that place
int NCR(int n, int r){
    int res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// print any n-th row of the pascal triangle
void findRow(int row){
    int ans = 1;
    cout << ans << " ";
    for(int i = 1; i < row; i++){
        ans = ans * (row - i);
        ans = ans / (i);
        cout << ans << " ";
    }
}

// given N, print the entire triangle
vector<int> generateRow(int row){
    vector<int> ansRow;
    long long ans = 1;
    ansRow.push_back(ans);
    for(int col = 1; col < row; col++){
        ans = ans * (row - col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i = 1; i <= numRows; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    // input
    /*int k;
    cout << "Enter the number of rows(N): ";
    cin >> k;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }*/


   //cout << NCR(3,2);
    findRow(1);

}