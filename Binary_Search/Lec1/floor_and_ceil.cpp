#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//floor
int findFloor(vector<int> &nums, int target){
    int n = nums.size();
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] <= target){
            ans = nums[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

// ceil
int lower_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = n;
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> floorAndCeil(vector<int> &nums, int target){
    int floor = findFloor(nums, target);
    int ceil = lower_bound(nums, target);
    return {floor, ceil};
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

    floorAndCeil(nums, target);

}