#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int findMinNum(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[low] <= nums[high]){
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            break;
        }
        if(nums[low] <= nums[mid]){
            if(nums[low] < ans){
                index = low;
                ans = nums[low];
            }
            low = mid + 1;
        }
        else{
            if(nums[mid] < ans){
                index = mid;
                ans = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
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

    cout << findMinNum(nums);

}