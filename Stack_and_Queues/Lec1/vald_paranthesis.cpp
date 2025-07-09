#include<iostream>
using namespace std;

// checking if a paranthesis string is valid or not 
bool validString(string s){
    stack<char> st; // stack to store the opening braces

    for(int i = 0; i < s.size(); i++){
        // pushing the opening braces
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        // comparing closing braces with respective opening ones
        // if not found, hence false
        else{
            if(st.empty()) return false;

            char ch = st.top();
            st.pop();

            if(s[i] == ')' && ch != '(' ||
                s[i] == '}' && ch != '{' ||
                s[i] == ']' && ch != '['){
                    return false;
                }
        }    
    }
    return st.empty(); // empty stack -> valid string
}

int main(){
    string s = "(())";
    cout << validString(s);
}