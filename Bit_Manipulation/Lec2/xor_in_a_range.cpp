#include<iostream>
using namespace std;

// finding the xor from 1 -> N
int func1(int n){
    if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else if(n % 4 == 3) return 0;
    else return n;
}

// finding the xor in a range (left -> right)
int func(int left, int right){
    return func1(left - 1) ^ func1(right);
}

int main(){
int left = 4;
int right = 8;
cout << func(left, right);
return 0;
}