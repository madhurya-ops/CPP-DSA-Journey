#include<iostream>
#include<math.h>
using namespace std;

// printing divisors of a number
vector<int> findDivisors(int n){
    vector<int> ans;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ans.push_back(i);
            if(n/i != i) ans.push_back(n/i);
        }
    }
    return ans;
}

int main(){
int n = 36;
vector<int> ans = findDivisors(n);
for(auto it : ans){
    cout << it << " ";
}
cout << endl;
}