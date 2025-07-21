#include<iostream>
using namespace std;
// logic: with every char, there is a substring that ends
// for better understanding: https://www.youtube.com/watch?v=xtqN4qlgr8s

int numberOfSubstrings(string s) {
    int lastSeen[3] = {-1, -1, -1};
    int cnt = 0;

    for(int i = 0; i < s.size(); i++){
        lastSeen[s[i] - 'a'] = i; // storing the last seen index of each unique char

        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            cnt = cnt + (1 + min(min(lastSeen[0], lastSeen[1]), lastSeen[2]));
        }
    }
    return cnt;
}

int main(){
string s = "bbacba";
cout << numberOfSubstrings(s);
}