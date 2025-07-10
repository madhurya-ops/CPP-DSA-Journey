#include<iostream>
using namespace std;

string postfix_to_infix(string s){
    int i = 0;
    stack<string> st;
    int n = s.size();
    
    while(i < n){
        // add the operands in the ans
        if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
                st.push(string(1, s[i]));
        }
        // (operator found): take out the last 2 entries in the stack 
        // put the operator b/w the pop() entries and surround the whole thing with ()
        // push the expression in the stack
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string expr = '(' + t2 + s[i] + t1 + ')';
            st.push(expr);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";
    string ans = postfix_to_infix(s);
    cout << ans;
}