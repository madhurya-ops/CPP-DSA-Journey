#include<iostream>
using namespace std;

// generating all the subsets using bit manipulation
vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;
        for(int num = 0; num <= subsets - 1; num++){
            vector<int> ds;
            for(int i = 0; i <= n-1; i++){
                if(num & (1 << i)) ds.push_back(nums[i]);
            }
            ans.push_back(ds);
        }
        return ans;
    }

int main(){
vector<int> nums = {1, 2, 3};
vector<vector<int>> ans = subsets(nums);

for(auto comb : ans){
    for(auto it : comb){
        cout << it << " ";
    }
    cout << endl;
}

return 0;
}