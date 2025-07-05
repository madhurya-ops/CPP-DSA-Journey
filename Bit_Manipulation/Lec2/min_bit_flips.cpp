#include<iostream>
using namespace std;

// counting the min bit flips req to convert to goal 
int minBitFlips(int start, int goal) {
    int ans = start ^ goal;
    int cnt = 0;
    for(int i = 0; i <= 31; i++){
        if(ans & (1 << i)) cnt = cnt + 1;
    }
    return cnt;
} 

int main(){
int start = 10;
int goal = 7;
cout << minBitFlips(start, goal);
return 0;
}