#include<iostream>
using namespace std;

// counting the number of set bits
// bruteforce
int countSetBits(int n){
    int cnt = 0;
    while(n > 1){
        cnt += n & 1;
        n = n >> 1;
    }
    if(n == 1) cnt += 1;
    return cnt;
}

// optimized
int countSetBits1(int n){
    int cnt = 0;
    while(n != 0){
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}   


int main(){
    int n = 13;
    cout << countSetBits(n);
}