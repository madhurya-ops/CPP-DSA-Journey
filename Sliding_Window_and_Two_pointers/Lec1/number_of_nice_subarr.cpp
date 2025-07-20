#include<iostream>
using namespace std;
// nice: count of odd integers == K
// exactly same as binary subarr with sum(prev prob)
// consider: odd -> 1 and even -> 0
// Formula: func(arr, goal) - func(arr, goal - 1)

int findSubarrays(vector<int> &nums, int goal){
    if(goal < 0) return 0; // edge case
    int left = 0;
    int right = 0;
    int cnt = 0;
    int sum = 0;

    while(right < nums.size()){
        sum += (nums[right] % 2); // increment the sum by adding each element
        // decrement the sum and increase the left ptr when sum > goal
        while(sum > goal){
            sum = sum - (nums[left] % 2);
            left++;
        }
        cnt = cnt + (right - left + 1); // subarrays for any element = length
        right++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return findSubarrays(nums, k) - findSubarrays(nums, k -1);
}

int main(){
vector<int> arr = {1, 1, 2, 1, 1};
int k = 3;
cout << numberOfSubarrays(arr, k);
}