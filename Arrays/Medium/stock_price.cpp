#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << maxProfit(nums);

}