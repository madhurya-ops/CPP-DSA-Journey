#include<iostream>
using namespace std;

// height is given, width is const i.e 1
// formula used: area = arr[i] * (nse - pse - 1)
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for(int i = 0; i < n; i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int element = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
                
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }
        st.push(i);
    }

    // for the elements which don't have nse or pse or both
    // we take, nse = n and pse = -1(if the stack is empty)
    while(!st.empty()){
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
    }
    return maxArea;
}

int main(){
vector<int> arr = {2, 1, 5, 6, 2, 3};
cout << largestRectangleArea(arr);
}