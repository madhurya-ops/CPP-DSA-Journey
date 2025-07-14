#include<iostream>
using namespace std;

// calculating largest - smallest in each sub-array and summing them up
vector<int> nextSmaller(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){ //  Use >= for NSE
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

vector<int> prevSmaller(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){ //  Use > for PSE
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

// calculating summaiton of sub array minimums
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> next = nextSmaller(arr);
    vector<int> prev = prevSmaller(arr);

    long long res = 0;
    for(int i = 0; i < n; ++i){
        long long left = i - prev[i];
        long long right = next[i] - i;
        long long contrib = (left * right) * arr[i];
        res = (res + contrib);
    }
    return res;
}

vector<int> nextGreater(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){ //  Use <= for NGE
            st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return res;
}

vector<int> prevGreater(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){ //  Use < for PGE
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return res;
}

// calculating summaiton of sub array maximums
int sumSubarrayMaxs(vector<int>& arr) {
    int n = arr.size();
    vector<int> next = nextGreater(arr);
    vector<int> prev = prevGreater(arr);

    long long res = 0;
    for(int i = 0; i < n; ++i){
        long long left = i - prev[i];
        long long right = next[i] - i;
        long long contrib = (left * right) * arr[i];
        res = (res + contrib);
    }
    return res;
}

// largest - smallest
long long subArrayRanges(vector<int>& nums) {
    long long maxSum = sumSubarrayMaxs(nums);
    long long minSum = sumSubarrayMins(nums);
    return maxSum - minSum;
}

int main(){
vector<int> arr = {1, 2, 3};
cout << subArrayRanges(arr);
}