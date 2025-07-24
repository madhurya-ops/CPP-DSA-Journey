#include<iostream>
using namespace std;

vector<int> findDenominations(int val){
    vector<int> deno = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // denominations
    int n = 9;
    vector<int> ans;

    for(int i = n-1; i >= 0; i--){
        // find denominations
        while(val >= deno[i]){
            val -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    return ans;
}

int main(){
    int v = 49;
    vector<int> ans =  findDenominations(v);

    for(auto it : ans){
        cout << it << " ";
    }
}