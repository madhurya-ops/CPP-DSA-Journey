#include<iostream>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;

    int profit = 0;
    for(int ind = n - 1; ind >= 0; ind--){
        for(int buy = 0; buy <= 1; buy++){
            if(buy){
                profit = max(
                    -prices[ind] - fee + ahead[0], 
                    0 + ahead[1]
                ); 
            }
            else{
                profit = max(
                    prices[ind] + ahead[1],
                    0 + ahead[0]
                );
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return curr[1];
}

int main(){
    vector<int> prices = {1, 3, 7, 5, 10, 3};
    int fee = 3;

    cout << maxProfit(prices, fee);
}