#include<iostream>
using namespace std;

int findFibo(int n){
    if(n <= 1){
        return n;
    }
    int last = findFibo(n-1);
    int slast = findFibo(n-2);
    return last + slast;
}

int main(){
    int n;
    cin >> n;
    cout << "The Fibonacci number is: " << findFibo(n);
}