#include<iostream>
using namespace std;
// First: find out the subarrays with sum <= k
// Second: apply this formula to get only the subarrays with sum = K
// Formula: func(arr, goal) - func(arr, goal - 1) 

int findSubarrays(vector<int> &nums, int goal){
    if(goal < 0) return 0; // edge case
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;

    while(right < nums.size()){
        sum += nums[right]; // increment the sum by adding each element
        // decrement the sum and increase the left ptr when sum > goal
        while(sum > goal){
            sum = sum - nums[left];
            left++;
        }
        cnt = cnt + (right - left + 1); // subarrays for any element = length
        right++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return findSubarrays(nums, goal) - findSubarrays(nums, goal -1);
}

int main(){
vector<int> nums = {1, 0, 0, 1, 1, 0};
int goal = 2;
cout << numSubarraysWithSum(nums, goal);
}