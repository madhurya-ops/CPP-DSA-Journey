#include<iostream>
using namespace std;

// Calculating pow(x^n) where n and x are int
double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = -1 * nn;
        while(nn){
            // if n is odd
            if(nn % 2){
                ans = ans * x;
                nn = nn - 1;
            }
            // if n is even
            else{
                x = x * x;
                nn = nn / 2;
            }
        }
        if(n < 0) ans = double(1.0) / double(ans);
        return ans;
    }

int main(){
    cout << myPow(2, 10);
    return 0;
}