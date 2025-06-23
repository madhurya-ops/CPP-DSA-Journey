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

Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    if(fast == NULL){
        return head->next;
        free(head);
    }
        
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete(delNode);
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 3;
    Node* head = convertArr2LL(arr);
    head = removeNthFromEnd(head, n);
    print(head);
    return 0;
}