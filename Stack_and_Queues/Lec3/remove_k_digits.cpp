#include<iostream>
using namespace std;

// remove k-digits from a given string
// reulting number should be the smallest
string removeKdigits(string num, int k) {
    int n = num.size();
    stack<char> st;

    if(k == n) return "0"; // all the digits removed

    // elements in the stack must be in ascending order
    // first element is smallest
    for(int i = 0; i < n; i++){
        // if st.top() is greater than the current element, pop it
        while(!st.empty() && k > 0 && ((st.top() - '0') > (num[i] - '0'))){
            st.pop();
            k = k-1;
        }
        st.push(num[i]);
    }

    // if k is still left(elements in stack are in ascending order), pop till k == 0
    while(k > 0){
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    // pop the elements from the stack and store them in "res"
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    // remove all the 0's occuring before the first non-zero digit: "0010" => "10"
    while(res.size() != 0 && res.back() == '0'){
        res.pop_back();
    }
        
    reverse(res.begin(), res.end()); // reversing the string "res" for the ans to be in the correct order

    if(res.empty()) return "0";

    return res;
}

int main(){
string s = "1432219";
int k = 3;
cout << removeKdigits(s, k);
}