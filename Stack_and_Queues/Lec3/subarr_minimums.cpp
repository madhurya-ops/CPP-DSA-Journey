#include<iostream>
using namespace std;

// finding the next smaller element
vector<int> findNSE(vector<int> &arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){ // strictly greater for NSE
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

// finding the previous smaller/equal element;
vector<int> findPSE(vector<int> &arr){
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){ 
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

// calculating the contribution and sum of indiv contributions by each element
// formula: total += right * left * arr[i]
// right subarrays = right smaller val ind - current ind
// left subarrays = current ind - left smaller/equal val ind  
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSE(arr);

    long long total = 0;
    const int mod = 1e9 + 7;

    // using mod to handle extra large ans val
    for(int i = 0; i < n; i++){
        long long left = i - pse[i];
        long long right = nse[i] - i;
        long long contrib = (left * right) % mod;
        contrib = (contrib * arr[i]) % mod;
        total = (total + contrib) % mod;
        }

    return (int)total;
}

int main(){
vector<int> arr = {3, 1, 2, 4};
cout << "The sum of min of all sub arr is: "<< sumSubarrayMins(arr);
}