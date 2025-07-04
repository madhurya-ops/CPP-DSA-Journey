#include<iostream>
using namespace std;

// checking if a number is a power of 2 or not
bool powOf2(int n){
    if(n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main(){
    int n = 16;
    cout << powOf2(n);
}