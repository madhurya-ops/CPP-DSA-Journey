#include<iostream>
using namespace std;

// dividing 2 int using bit manipulation
int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;

    bool sign = (dividend >= 0) == (divisor >= 0); // negative sign on quotient handling

    long n = abs((long)dividend);
    long d = abs((long)divisor);
    long quotient = 0; // ans

    while(n >= d){
        int cnt = 0;
        while(n >= (d << (cnt + 1))){
            cnt += 1;
        }
        quotient += 1 << cnt;
        n -= d << cnt;
    }

    if(quotient == (1 << 31) && sign) return INT_MAX;
    if(quotient == (1 << 31) && !sign) return INT_MIN;

    return sign ? quotient : -quotient;
}


int main(){
    int dividend = 22;
    int divisor = 3;
    cout << divide(dividend, divisor);
}