#include<iostream>
using namespace std;

// reversing the string, managing the brackets
string reverseS(string s){
    int front = 0;
    int end = s.size() - 1;

    while(front <= end){
        char left = s[front];
        char right = s[end];

        if(left == '(') left = ')';
        else if(left == ')') left = '(';

        if(right == ')') right = '(';
        else if(right == '(') right = ')';

        s[front] = right;
        s[end] = left;

        front++;
        end--;
    }
    return s;
}

// priority function
int getPriority(char op){
    switch(op){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1; // for any other operators
    }
}

string infix_to_prefix(string str){
    string s = reverseS(str); // reverse
    int i = 0;
    stack<char> st;
    string ans = "";
    int n = s.size();

    while(i < n){
        // add the operands in the ans
        if((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
                ans += s[i];
        }
        // pushing the opening bracket in the stack
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // when a closing bracket is found, pop the stack till an opening '(' found
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // when a lower priority operator is to be added in the stack,
        // the operator with higher prior is pop() and added to ans
        // all same prior op can be in the stack at the same time except '^'
        else{
            if(s[i] == '^'){
                while(!st.empty() && getPriority(s[i]) <= st.top()){
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && getPriority(s[i]) < getPriority(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            
        }
        i++;
    }

    // pushing the remaining operators in the ans from stack
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return reverseS(ans);
}

int main(){
    string s = "(A+B)*C-D+F";
    string ans = infix_to_prefix(s);
    cout << ans << endl;
    
}