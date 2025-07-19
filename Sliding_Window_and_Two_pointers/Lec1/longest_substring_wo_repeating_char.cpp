#include<iostream>
using namespace std;

// solved using sliding window
int lengthOfLongestSubstring(string s) {
    int hash[256]; // declaring a hash-array, 256: no. of known characters
    fill(hash, hash + 256, -1); // filling the hash-arr with -1 initially

    int n = s.size();
    int left = 0;
    int right = 0;
    int maxLen = 0;

    while(right < n){
        // if the char is in the map
        if(hash[s[right]] != -1){
            // if the repeating char is in the window size
            // shift the left pointer to right + 1
            if(hash[s[right]] >= left){
                left = hash[s[right]] + 1;
            }
        }
        // compare and store the max length
        int len = right - left + 1;
        maxLen = max(maxLen, len);

        // store the char's index in the hash-arr
        hash[s[right]] = right;
        right++;
    }
    return maxLen;
}

int main(){
string s = "cadbzabcd";
cout << lengthOfLongestSubstring(s);
}