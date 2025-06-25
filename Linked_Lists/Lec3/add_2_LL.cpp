#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

//converting arr to Linked-List
Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Print the Linked-List
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Adding 2 LLs
// LLs given in reversed order
// Answer returned in reverse order
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dNode = new Node(-1);
    Node* curr = dNode;
    Node* temp1 = l1;
    Node* temp2 = l2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dNode->next;
}

int main(){
    vector<int> arr1 = {3, 5};
    vector<int> arr2 = {4, 5, 9, 9};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node* head = addTwoNumbers(head1, head2);
    print(head);
    return 0;
}