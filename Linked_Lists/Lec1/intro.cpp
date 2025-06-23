#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

// convert array to LL
// return head of the LL
Node* convertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// how to return the length of the LL
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// check if a value is present in the LL
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArrToLL(arr);
    // cout << head->data << endl;
    
    // how to traverse in a LL
    /*Node* temp = head;
    while(temp){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    */

    //cout << lengthOfLL(head);

    cout << checkIfPresent(head, 5);
    
}