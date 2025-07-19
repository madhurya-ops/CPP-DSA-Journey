#include<iostream>
using namespace std;

int characterReplacement(string s, int k) {
    int left = 0;
    int right = 0;
    int maxFreq = 0;
    int maxLen = 0;
    int n = s.size();
    int hash[26] = {0};

    while(right < n){
        //updating maxFreq at each move
        hash[s[right] - 'A']++; 
        maxFreq = max(maxFreq, hash[s[right] - 'A']); 

        // decrease the freq in the map and incrase the left ptr
        if((right - left + 1) - maxFreq > k){
            hash[s[left] - 'A']--;
            left++;
        }

        // if in range then calc the maxLen
        if((right - left + 1) - maxFreq <= k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main(){
string s = "AAABBCCD";
int k = 2;
cout << characterReplacement(s, k);
}