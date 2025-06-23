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

// finding the middle of the LL
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// merging 2 sorted LL
Node* mergeTwoLists(Node* list1, Node* list2){
    Node* dNode = new Node(-1);
    Node* temp = dNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;
    return dNode->next;
}

// sorting 2 LL
Node* sortList(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = NULL;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);
    return mergeTwoLists(leftHead, rightHead);
}

int main(){
    vector<int> arr = {1, 3, 4, 7, 2};
    Node* head = convertArr2LL(arr);
    head = sortList(head);
    print(head);
    return 0;
}