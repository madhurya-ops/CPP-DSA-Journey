#include<iostream>
#include <map>
using namespace std;

int func(string s, int k){
    int left = 0;
    int right = 0;
    int maxLen = 0;
    map<char, int> mpp;

    while(right < s.size()){
        mpp[s[right]]++;

        if(mpp.size() > k){
            mpp[s[left]]--;
            if(mpp[s[left]] == 0) mpp.erase(s[left]);
            left++;
        }

        if(mpp.size() <= k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main(){
string s = "aaabbccd";
int k = 2;
cout << func(s, k);
}