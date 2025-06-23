#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int countSubarrays(vector<int> &nums, int k){
    int n = nums.size();
    int xr = 0;
    int count = 0;
    map<int, int> mpp;
    mpp[xr]++;
    for(int i = 0; i < n; i++){
        xr = xr ^ nums[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}

int main(){
    // input
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << countSubarrays(nums, k);

}