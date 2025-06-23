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

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// converting arr to Doubly Linked-List
Node* convertArr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Deleting the head of the DLL
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete(prev);
    return head;
}

// Deleting the tail of the DLL
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete(tail);
    return head;
}

// Deleting the k-th node of the DLL
Node* deleteKthElement(Node* head, int k){
    if(head == NULL) return NULL;
    int cnt = 0;
    Node* kNode = head;
    while(kNode != NULL){
        cnt++;
        if(cnt == k) break;
        kNode = kNode -> next;
    }

    Node* prev = kNode -> back;
    Node* front = kNode -> next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        deleteHead(head);
    }
    else if(front == NULL){
        deleteTail(head);
    }
    
    prev->next = front;
    front->back = prev;

    kNode->back = nullptr;
    kNode->next = nullptr;
    delete kNode;

    return head;
}

// INSERTING
// Inserting before the head of the DLL
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

// Inserting before the tail of the DLL
Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL) return insertBeforeHead(head, val);

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// Insert before the k-th element of the DLL
Node* insertBeforeKth(Node* head, int val, int k){
    if(k == 1) return insertBeforeHead(head, val);

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    int el = 10;
    int k = 3;
    int val = 5;
    Node* head = convertArr2DLL(arr);
    head = insertBeforeHead(head, val);
    print(head);
    return 0;
}