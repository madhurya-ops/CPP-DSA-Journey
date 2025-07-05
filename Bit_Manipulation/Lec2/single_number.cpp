#include<iostream>
using namespace std;

// finding the number that appears only once in an array/vector
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        ans ^= nums[i];
    }
    return ans;
}

int main(){
vector<int> nums = {4, 1, 2, 1, 2};
cout << singleNumber(nums);
return 0;
}