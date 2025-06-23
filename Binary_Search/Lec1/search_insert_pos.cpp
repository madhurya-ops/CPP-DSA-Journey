#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
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

    cout << searchInsert(nums, target);

}