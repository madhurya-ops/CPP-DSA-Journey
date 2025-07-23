#include<iostream>
using namespace std;

int assignCookies(vector<int> &g, vector<int> &s){
    int n = g.size();
    int m = s.size();
    int child = 0;
    int cookie = 0;

    // sort both the arr before the operation
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // continue to increase the cookies if the child is not satisfied
    while(child < n && cookie < m){
        if(g[child] <= s[cookie]){
            child++;
        }
        cookie++;
    }
    // return the number of children satisfied
    return child;
}

int main(){
vector<int> greedy = {1, 5, 3, 3, 4};
vector<int> s = {4, 2, 1, 2, 1, 3};
cout << assignCookies(greedy, s);
}