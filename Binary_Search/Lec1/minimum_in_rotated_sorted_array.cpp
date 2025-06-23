#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

// optimised
int findMinNum(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[low] <= nums[high]){
            ans = min(ans, nums[low]);
            break;
        }
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else{
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    // input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << findMin(nums);

}