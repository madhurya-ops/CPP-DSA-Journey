#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, count = 0;
    for(int i = 0; i < n; i++){
        preSum += nums[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum] += 1;
    }
    return count;
}

int main(){
    // input
    int k;
    cout << "Enter the value of K: ";
    cin >> k;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

   subarraySum(nums, k);

}