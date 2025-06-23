#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            return true;
        }
        // to resolve the duplicates issue
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        // left sorted
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return - 1;
}

int main(){
    // input
    int target;
    cout << "Enter the target: ";
    cin >> target;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << search(nums, target);

}