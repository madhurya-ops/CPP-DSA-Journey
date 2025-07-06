#include<iostream>
using namespace std;

// counting the number of primes till number n
int countPrimes(int n) {
        if(n < 2) return 0; // edge case
        vector<int> prime(n, 1); // creating a list with every no marked as 1
        int cnt = 0;
        // converting every non-prime no in the list as 0
        for(int i = 2; i * i <= n-1; i++){
            if(prime[i] == 1){
                for(int j = i * i; j <= n-1; j += i) prime[j] = 0;
            }
        }
        // counting the no of primes
        for(int i = 2; i < n; i++){
            if(prime[i] == 1) cnt += 1;
        }
        return cnt;
    }

int main(){
    int n = 5;
    cout << countPrimes(n);
}