#include<iostream>
using namespace std;

// summation of all the subsets
// output in sorted order
void func(int ind, int sum, vector<int> &arr, int n, vector<int> &ds){
    if(ind == n){
        ds.push_back(sum);
        return;
    }
    // pick
    func(ind+1, sum + arr[ind], arr, n , ds);

    // not-pick
    func(ind+1, sum, arr, n, ds);
}

int main(){
    vector<int> arr= {3, 1, 2};
    int n = arr.size();
    vector<int> sumSubset;
    func(0, 0, arr, n, sumSubset);
    sort(sumSubset.begin(), sumSubset.end()); // to display the sum in sorted order
    
    for(auto it : sumSubset){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}