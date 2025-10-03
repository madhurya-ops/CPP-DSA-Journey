#include<iostream>
using namespace std;

int robber(vector<int>& nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = 0 + prev;

        int cur_i = max(take, notTake);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int rob(vector<int>& valueInHouse) {
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(int i = 0; i < n; i++){
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n - 1) temp2.push_back(valueInHouse[i]);
    }
    return max(robber(temp1), robber(temp2));
}

int main(){
    vector<int> valueInHouse = {1, 2, 3, 1};

    cout << rob(valueInHouse);
}