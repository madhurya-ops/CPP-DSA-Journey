#include<iostream>
using namespace std;

string postfix_to_prefix(string s){
    int n = s.size();
    int i = 0;
    stack<string> st;

    while(i < n){
        // add the operands in the ans
        if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
                st.push(string(1, s[i]));
        }
        // when an operator is found pop 2 elements from the stack
        // and push them back in this order: op + t2 + t1
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string exp = s[i] + t2 + t1;
            st.push(exp);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";
    string ans = postfix_to_prefix(s);
    cout << ans;
}