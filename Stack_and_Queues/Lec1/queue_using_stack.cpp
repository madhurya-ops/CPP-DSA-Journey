#include<iostream>
#include<queue>
using namespace std;

// Implementing queue using stack
class MyQueue {
public:

    stack<int> S1, S2;

    MyQueue() {}
    
    void push(int x) {
        S1.push(x);
    }
    
    int pop() {
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }
        int front = S2.top();
        S2.pop();
        return front;
    }
    
    int peek() {
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }
        return S2.top();
    }
    
    bool empty() {
        return S1.empty() && S2.empty();
    }
};

int main(){
    MyQueue* obj = new MyQueue();
obj->push(1);
obj->push(2);
int a = obj->peek();  // returns 1
int b = obj->pop();   // returns 1
bool c = obj->empty();
cout << a << endl << b;
}