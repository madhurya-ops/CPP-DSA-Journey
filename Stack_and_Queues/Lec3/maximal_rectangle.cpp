#include<iostream>
using namespace std;

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

    while(!st.empty()){
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, heights[element] * (nse - pse - 1));
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxArea = 0;
    vector<vector<int>> pSum(n, vector<int>(m, 0)); // prefix sum matrix
    
    for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += matrix[i][j] - '0';
            if(matrix[i][j] == '0'){
                sum = 0;
            }
            pSum[i][j] = sum;
        }
    }

    // serving each and every row to find out the maxArea of 1's possible
    for(int i = 0; i < n; i++){
        maxArea = max(maxArea, largestRectangleArea(pSum[i]));
    }

    return maxArea;
}

int main(){
vector<vector<char>> matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};
cout << maximalRectangle(matrix);                           
}