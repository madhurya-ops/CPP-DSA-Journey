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

Node* getIntersectionNode(Node *headA, Node *headB) {
    if(headA == NULL || headB == NULL) return NULL;

    Node* t1 = headA;
    Node* t2 = headB;

    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2) return t1;

        if(t1 == NULL) t1 = headB;
        if(t2 == NULL) t2 = headA;
    }
    return t1;
}

int main(){
    vector<int> arr1 = {1, 0, 1, 2, 0, 2, 1};
    vector<int> arr2 = {1, 0, 1, 2, 0, 2, 1};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node * newHead = getIntersectionNode(head1, head2);
    return 0;
}