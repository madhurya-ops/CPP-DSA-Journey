#include<iostream>
using namespace std;

// next greatest element 2
// finding the NGE in a circular arr
vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = 2*n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(i < n){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }

int main(){
    vector<int> nums = {2, 10, 12, 1, 11};
    vector<int> ans = nextGreaterElements(nums);

    for(auto it : ans){
        cout << it << " ";
    }
}