#include<iostream>
using namespace std;

// when 2 arr are given and arr1 is a subset of arr2
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mpp; // nge, arr[i]
    stack<int> st;

    // mapping the nge for elements in arr1 from arr2
    for(int i = nums2.size()-1; i >= 0; i--){
        while(!st.empty() && st.top() < nums2[i]){
            st.pop();
        }
        if(st.empty()){
            mpp[nums2[i]] = -1;
        } 
        else{
            mpp[nums2[i]] = st.top();
        } 
        st.push(nums2[i]);
    }

    vector<int> ans;
    for(int i = 0; i < nums1.size(); i++){
        ans.push_back(mpp[nums1[i]]);
    }

    return ans;
}

// when the nge is to be found from one arr only
vector<int> findNGE(vector<int> &arr){
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }else{
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

int main(){
    vector<int> arr1 = {4, 1, 2};
    vector<int> arr2 = {1, 3, 4, 2};

    vector<int> ans1 = findNGE(arr2);
    vector<int> ans2 = nextGreaterElement(arr1, arr2);

    // output for findNGE
    for(auto it : ans1){
        cout << it << " ";
    }
    cout << endl;

    // output for nextGreaterElement
    for(auto it : ans2){
        cout << it << " ";
    }
    cout << endl;
}