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

// Reverse the LL(ITERATIVE)
Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Iterating to get the Kth Node
Node* getKthNode(Node* temp, int k){
    k -= 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

// Reversing the LL in K-groups
Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    Node* prevNode = NULL;
    while(temp != NULL){
        Node* KthNode = getKthNode(temp, k);
        if(KthNode == NULL){
            if(prevNode != NULL) prevNode->next = temp;
            break;
        }
        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        reverseLL(temp);

        if(temp == head) head = KthNode;
        else prevNode->next = KthNode;

        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;
    Node* head = convertArr2LL(arr);
    head = reverseKGroup(head, k);
    print(head);
    return 0;
}