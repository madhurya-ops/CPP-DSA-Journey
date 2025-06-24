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

// Deleting all occurences of "key" in a DLL
Node* deleteAllOccurences(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head) head = temp->next;

            Node* nextNode = temp->next;
            Node* prevNode = temp->back;

            if(nextNode) nextNode->back = prevNode;
            if(prevNode) prevNode->next = nextNode;
            
            free(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {9, 9, 7, 5};
    int key = 9;
    Node* head = convertArr2LL(arr);
    head = deleteAllOccurences(head, key);
    print(head);
    return 0;
}