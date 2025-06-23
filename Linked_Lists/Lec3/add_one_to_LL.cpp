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

int addHelper(Node* temp){
    if(temp == NULL) return 1;
    int carry = addHelper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head){
    int carry = addHelper(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        head = newHead;
        return newHead;
    }
    return head;
}

int main(){
    vector<int> arr = {9, 9, 9, 9};
    Node* head = convertArr2LL(arr);
    head = addOne(head);
    print(head);
    return 0;
}