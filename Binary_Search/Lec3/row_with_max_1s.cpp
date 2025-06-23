#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int lower_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    int cnt_max = 0;
    int index = -1;
    for(int i = 0; i < n; i++){
        int cnt_ones = m - lower_bound(matrix[i], 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
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

    cout << rowWithMax1s(matrix, n, m);

}