#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node* child;

    public:
    Node(int data1, Node* next1, Node* back1, Node* child1){
        data = data1;
        next = next1;
        back = back1;
        child = child1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

// Creates child in a given node
Node* createChildList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->child = new Node(arr[i]);
        curr = curr->child;
    }
    return head;
}

// Print the Linked-List
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Merging the LLs
Node* merge2LL(Node* list1, Node* list2){
    Node* dNode = new Node(-1);
    Node* res = dNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }
    if(list1) res->child = list1;
    else res->child = list2;
    return dNode->child;
}

// Flattening the LLs(Recursion)
Node* flattenLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mergedHead = flattenLL(head->next);
    return merge2LL(head, mergedHead);
}

int main(){
    // Create vertical child lists
    Node* head1 = createChildList({1, 2, 3});
    Node* head4 = createChildList({4, 5, 8});
    Node* head6 = createChildList({6, 7});

    // Connect them using next pointers (top-level horizontal)
    head1->next = head4;
    head4->next = head6;
    Node* flatHead = flattenLL(head1);
    print(flatHead);
    return 0;
}