#include<iostream>
using namespace std;

// standing at the first element can you reach the last element 
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxInd = 0;

    for(int i = 0; i < n; i++){
        // if the current index > maxInd: there is no path to reach the end
        if(i > maxInd) return false;

        maxInd = max(maxInd, nums[i] + i);
    }
    return true;
}

int main(){
vector<int> nums = {1, 2, 3, 1, 1, 0, 2, 5};
cout << canJump(nums);
}