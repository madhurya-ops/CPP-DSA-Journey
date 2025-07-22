#include<iostream>
#include <map>
using namespace std;
// using modified sliding window approach 
// formula: func(arr, k) - func(arr, k-1)

int func(vector<int> &nums, int k){
    int left = 0;
    int right = 0;
    int cnt = 0;
    map<int, int> mpp;

    while(right < nums.size()){
        mpp[nums[right]]++;

        while(mpp.size() > k){
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0){
                mpp.erase(nums[left]);
            }
            left++;
        }
        cnt += (right - left + 1);
        right++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return func(nums, k) - func(nums, k-1);
}

int main(){
vector<int> nums = {2, 1, 1, 1, 3, 4, 3, 2};
int k = 2;
cout << subarraysWithKDistinct(nums, k);
}