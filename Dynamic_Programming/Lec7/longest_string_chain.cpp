#include<iostream>
using namespace std;

bool checkPossible(string &S1, string &S2){
    if( S1.size() != S2.size() + 1) return false;

    int first = 0;
    int second = 0;

    while(first < S1.size()){
        if(second < S2.size() && S1[first] == S2[second]){
            first++;
            second++;
        }
        else {
            first++;
        }
    }
    if(first == S1.size() && second == S2.size()) return true;
    return false;
}

static bool comp(string &S1, string &S2){
    return S1.size() < S2.size();
}

int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(checkPossible(words[i], words[j]) && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
        }
    }
    return maxi;
}

int main(){
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << longestStrChain(words);
}