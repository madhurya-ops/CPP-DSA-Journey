#include<iostream>
using namespace std;

int findSubarrays(vector<int> &nums, int goal){
    if(goal < 0) return 0;
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;

    while(right < nums.size()){
        sum += nums[right];
        while(sum > goal){
            sum = sum - nums[left];
            left++;
        }
        cnt = cnt + (right - left + 1);
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