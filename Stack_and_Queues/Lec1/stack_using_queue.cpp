#include<iostream>
#include<queue>
using namespace std;

// Implementing stack using queue
class st {
queue<int> q;

public:
    // push
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 1; i <= s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    // pop
    int pop() {
        if(q.empty()){
            cout << "Stack is empty!\n";
            return -1;
        }
        int top = q.front();
        q.pop();
        return top;
    }
    
    // return the top el
    int top() {
        if(q.empty()){
            cout << "Stack is empty!\n" << endl;
            return -1;
        }
        return q.front();
    }

    // return 1 if stack empty
    bool empty(){
        return q.empty();
    }


};

int main(){
    st s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top();
    cout << s.empty();
}