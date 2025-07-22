#include<iostream>
using namespace std;
// using two-ptr & sliding window approach
// the window is expanded rightwards till all the elements of 't' are found
// then the window starts shrinking from left to capture the min length
// cnt: keeps a track that all the elements of 't' are present in the current substring
// minLen and startInd: continuously updated to keep a track of the min window substr

string minWindow(string s, string t) {
    int hash[256] = {0};
    int left = 0;
    int right = 0;
    int cnt = 0;
    int minLen = INT_MAX;
    int startInd = -1;
    int n = s.size();
    int m = t.size();

    // adding all the char of 't' in the hash array
    for(int i = 0; i < m; i++){
        hash[t[i]]++;
    }
        
    while(right < n){
        // when char of 't' is found in 's', the cnt is increased
        if(hash[s[right]] > 0){
            cnt++;
        }
        // then -1 for each char, for each time they occur
        hash[s[right]]--;

        // when all the chars of 't' are found in the substring
        while(cnt == m){
            // update the min length
            if((right - left + 1) < minLen){
                minLen = right - left + 1;
                startInd = left;
            }
            // before moving the left ptr, increase the char in the hash (+1),
            // to restore the changes made
            hash[s[left]]++;
            if(hash[s[left]] > 0){
                cnt--; // means that a char from 't' is removed from the current substring
            }
            left++;
        }
        right++;
    }
    // return an empty string if no min window substring is found
    return startInd == -1 ? "" : s.substr(startInd, minLen);
}

int main(){
string s = "ddaaabbca";
string t = "abc";
cout << minWindow(s, t);
}