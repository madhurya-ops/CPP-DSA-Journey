#include<iostream>
#include<queue>
using namespace std;

// Implementing min stack(stack that store the min value)
// formula: new val = 2*val - prev min
class MinStack {
    stack<long long int>s;
    long long int minVal;

public:
    MinStack() {}
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal=val;
        }
       else if(val<minVal){
            s.push((long long)2*val-minVal);
            minVal=val;
        }
        else s.push(val);

    }
    
    void pop() {
        if(s.top()<minVal){
            minVal=2*minVal-s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<minVal)return minVal;
        else return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

int main(){
    MinStack st;
    st.push(12);
    st.push(15);
    st.push(10);
    cout << st.getMin();
}