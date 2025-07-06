#include<iostream>
#include<math.h>
using namespace std;

// printing prime factors of a number
vector<int> findPrimeFactors(int n){
    vector<int> ans;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0){
                n = n / i;
            }
        }
    }
    if(n != 1) ans.push_back(n);
    return ans;
}

int main(){
int n = 36;
vector<int> ans = findPrimeFactors(n);
for(auto it : ans){
    cout << it << " ";
}
cout << endl;
}