#include<iostream>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // price, index
    int ind = -1;

    StockSpanner() {
        ind = -1;
        // clearing the stack before performing on another dataset
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int price) {
        ind = ind + 1; 
        // strictly maintaining a decreasing order inside the stack 
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        // formula: current index - index of prev greater element
        int ans = ind - (st.empty() ? -1 : st.top().second);
        // pushing the current price and index after updating the ans 
        st.push({price, ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


int main(){

}