#include<iostream>
using namespace std;

// finding the two numbers that appear only once in an array/vector
vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    long xorr = 0;
    for(int i = 0; i < n; i++) xorr = xorr ^ nums[i];
    int rightmost = (xorr & (xorr - 1)) ^ xorr; // segregating the righmost bit that is different in both the nums that appear only once
    int b1 = 0; // bucket 1
    int b2 = 0; // bucket 2
    for(int i = 0; i < n; i++){
        if(nums[i] & rightmost) b1 = b1 ^ nums[i];
        else b2 = b2 ^ nums[i];
    }
    return {b1, b2};
}

int main(){
vector<int> nums = {2, 4, 2, 6, 3, 7, 7, 3};
vector<int> ans = singleNumber(nums);
for(auto it : ans){
    cout << it << " ";
}
cout << endl;
return 0;
}