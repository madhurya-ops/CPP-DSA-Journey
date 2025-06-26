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

// Finding the (new) tail of the rotated LL
Node* findNthNode(Node* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

// Rotating the LL, K-times(rejoining the links)
Node* rotateRight(Node* head, int k) {
    if(head == NULL || k == 0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        len++;
        tail = tail->next;
    }
    if(k % len == 0) return head;
    k = k % len;
    tail->next = head;
    Node* newTail = findNthNode(head, len - k);
    head = newTail->next;
    newTail->next = NULL;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    Node* head = convertArr2LL(arr);
    head = rotateRight(head, k);
    print(head);
    return 0;
}