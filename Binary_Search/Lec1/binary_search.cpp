#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
// recursive bs
int bs(vector<int> &nums, int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(nums[mid] == target)
        return mid;
    else if(target > nums[mid])
        return bs(nums, mid + 1, high, target);
    return bs(nums, mid - 1, high, target);
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    return bs(nums, 0, n - 1, target);
}

// non-recursive
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(target == nums[mid]) return mid;
        else if(target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    // input
    int target;
    cout << "Enter the target: ";
    cin >> target;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << search(nums, target);

}