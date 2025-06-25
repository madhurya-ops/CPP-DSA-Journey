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

// Print the Linked-List
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// find the tail
Node* findTail(Node* head){
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}

// find the pairs
vector<pair<int, int>> findPair(Node* head, int sum){
    vector<pair<int, int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data){
        if(left->data + right->data == sum){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < sum){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 9};
    int key = 5;
    Node* head = convertArr2DLL(arr);
    vector<pair<int, int>> ans = findPair(head, key);
    for(const auto& i : ans){
        cout << "(" << i.first << "," << i.second << ")" << " ";
    }
    cout << endl;
    return 0;
}