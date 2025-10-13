#include<iostream>
using namespace std;

bool f4(int k, vector<int> &arr){
    int n = arr.size();
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;

    if(arr[0] <= k){
        prev[arr[0]] = true; 
    }
        

    for(int i = 1; i < n; i++){
        for(int target = 0; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[i]) take = prev[target - arr[i]];

            curr[target] = notTake || take;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }

    if(sum % 2) return false;
    int target = sum / 2;
    return f4(target, nums);
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);
}