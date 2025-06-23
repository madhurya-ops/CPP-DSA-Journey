#include<iostream>
#include<algorithm>
#include <unordered_set>
using namespace std;

//optiomal approach(set)
int longestConsecutiveElements(vector<int> &nums){
    int n = nums.size();
    int longest = 1;
    unordered_set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(nums[i]);
    }
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int count = 1;
            int x = it;
            while(st.find(x + 1) != st.end()){
                x += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

// better approach-O(N)
int longestConsecutiveSequence(vector<int> &nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    int lastSmaller = INT_MIN;
    int longest = 1;
    for(int i = 0; i < n; i++){
        if(nums[i] - 1 == lastSmaller){
            count +=1;
            lastSmaller = nums[i];
        }else if(lastSmaller != nums[i]){
            count = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

   longestConsecutiveSequence(nums);

}