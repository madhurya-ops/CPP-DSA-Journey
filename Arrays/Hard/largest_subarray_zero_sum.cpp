#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int maxLen(vector<int> &nums, int n){
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << maxLen(nums, n);

}