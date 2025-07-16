#include<iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for(int i = 0; i < n; i++){
        // only evaluating the maxi in the given range of K(window size)
        if(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        // maintaining a decreasing order, pop all the elements less/equal to the current element
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i); // push the current index
        // add the element to ans list when the window is sliding
        if(i >= k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(){
    int k = 3;
    vector<int> nums = {1, 3, -2, -3, 5, 3, 2, 1, 6};
    vector<int> ans = maxSlidingWindow(nums, k);

    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}