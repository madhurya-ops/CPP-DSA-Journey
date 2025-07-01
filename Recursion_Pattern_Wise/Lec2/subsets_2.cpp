#include<iostream>
using namespace std;

void func(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds); // to first add the empty subset and then other
    for(int i = ind; i < arr.size(); i++){
        if(i != ind && arr[i] == arr[i-1]) continue; // to ignore the duplicate values
        ds.push_back(arr[i]);
        func(i+1, arr, ds, ans);
        ds.pop_back();
    }
}

int main(){
    vector<int> arr= {1, 2, 2};
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // for our logic to work
    func(0, arr, ds, ans);
    
    
    for(auto comb : ans){
        for(auto it : comb){
            cout << it << " ";
        }
        cout << endl;
    }
    
    return 0;
}