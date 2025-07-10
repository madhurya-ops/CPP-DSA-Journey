#include<iostream>
using namespace std;

string prefix_to_infix(string s){
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
        // (operator found): take out the last 2 entries in the stack 
        // put the operator b/w the pop() entries and surround the whole thing with ()
        // push the expression in the stack
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string expr = '(' + t1 + s[i] + t2 + ')';
            st.push(expr);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s = "*+PQ-MN";
    string ans = prefix_to_infix(s);
    cout << ans;
}