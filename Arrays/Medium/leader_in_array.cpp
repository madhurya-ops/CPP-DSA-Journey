#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

vector<int> findLeaders(vector<int> &nums){
    vector<int> ans;
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i = n - 1; i >= 0; i--){
        if(nums[i] > maxi){
            ans.push_back(nums[i]);
        }
        maxi = max(maxi, nums[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

   findLeaders(nums);

}