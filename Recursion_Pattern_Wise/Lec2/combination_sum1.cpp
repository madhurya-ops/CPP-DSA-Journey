#include<iostream>
using namespace std;

// finding the combination for sum(target), repeating value allowed
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(ind == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    // pick
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    // not pick
    findCombination(ind+1, target, arr, ans, ds);
}

int main(){
    int target = 7;
    vector<int> arr= {2, 3, 6, 7};
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, arr, ans, ds);

    for(auto comb : ans){
        for(auto num : comb){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}