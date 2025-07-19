#include<iostream>
using namespace std;
// Think of this problem as: longest subarray with at most k-zeros

int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int zeros = 0;

    while(right < nums.size()){
        // increase the count of zeros when found
        if(nums[right] == 0) zeros++;

        // when 0's > K, then move forward the left ptr and if a zero is found,
        // decrease the count of zeros 
        if(zeros > k){
            if(nums[left] == 0) zeros--;
            left++;
        }
        // calc the length only when 0s are in the given range
        if(zeros <= k){
            int len = right - left + 1;
            maxLen = max(len, maxLen);
        }
        right++;
    }
    return maxLen;
}

int main(){
vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
int k = 2;
cout << longestOnes(arr, k);
}