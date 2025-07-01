#include<iostream>
using namespace std;

// finding the combination for sum(target), repeating value not-allowed
// answer in a sorted order
void findValue(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    sort(arr.begin(), arr.end());
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for(int i = ind; i < arr.size(); i++){
        // check to not continue with same values as the first no. 
        if(i > ind && arr[i] == arr[i-1]) continue;
        // stop expanding the tree once the arr[i] > target
        if(arr[i] > target) break;
        // if a value does not meet the above condn
        // add the value in the ds
        ds.push_back(arr[i]);
        findValue(i+1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

int main(){
    int target = 5;
    vector<int> arr= {2, 5, 2, 1, 2};
    vector<vector<int>> ans;
    vector<int> ds;
    findValue(0, target, arr, ans, ds);

    for(auto comb : ans){
        for(auto num : comb){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}