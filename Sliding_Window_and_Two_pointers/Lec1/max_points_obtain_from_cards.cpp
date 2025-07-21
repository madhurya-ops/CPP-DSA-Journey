#include<iostream>
using namespace std;

int maxScore(vector<int> &nums, int k){
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;
    int n = nums.size();

    // pick k elements from the left window
    for(int i = 0; i < k; i++){
        leftSum += nums[i];
    }
    maxSum = leftSum;

    // start shrinking the left window and expand the right window simultaneously
    // also, keep comparing and store the max result of leftSum + rightSum
    for(int i = 0; i < k; i++){
        rightSum += nums[n - 1 - i];
        leftSum -= nums[k - 1 - i];
        maxSum = max(maxSum, leftSum + rightSum);
    }
    return maxSum;
}

int main(){
vector<int> nums = {6, 2, 3, 4, 7, 2, 1, 7, 1};
int k = 4;
cout << maxScore(nums, k);
}