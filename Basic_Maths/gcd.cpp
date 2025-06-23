#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }else{
            b = b % a;
        } 
    } 
    if(a == 0) return b;
            return a;
}

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    cout<< "GCD is: " << gcd(num1, num2);
}