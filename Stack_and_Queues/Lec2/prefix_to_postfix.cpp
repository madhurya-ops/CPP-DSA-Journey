#include<iostream>
using namespace std;

string prefix_to_postfix(string s){
    int n = s.size();
    int i = n-1;
    stack<string> st;

    while(i >= 0){
        // add the operands in the ans
        if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
                st.push(string(1, s[i]));
        }
        // when an operator is found pop 2 elements from the stack
        // and push them back in this order: t1 + t2 + op
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string exp = t1 + t2 + s[i];
            st.push(exp);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s = "/-AB*+DEF";
    string ans = prefix_to_postfix(s);
    cout << ans;
}