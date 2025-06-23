#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

// convert array to LL
// return head of the LL
Node* convertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// DELETION
// deleting head of LL
Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp; // free up the memory
    return head;
}

//deleting tail of LL
Node* removesTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

// deleting Kth element in LL
Node* deleteK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

// deleting a certain value from LL
Node* deleteEl(Node* head, int el){
    if(head == NULL) return head;
    if(head -> data == el){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == el){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

// INSERTION
// Inserting at the head of the LL
Node* insertHead(Node* head, int val){
   return new Node(val, head);
}

// Insertion at the tail of the LL
Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    temp -> next = newNode;
    return head;
}

// Inserting at Kth position
Node* insertPosition(Node* head, int el, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
        }
        else return head;
    }
    if(k == 1){
        return new Node(el, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(el, temp->next);
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// Inserting an element before the value x
Node* insertBeforeValue(Node* head, int el, int val){
    if(head == NULL) return NULL;
    if(head->data == val){
        return new Node(el, head);
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el, temp->next);
            temp -> next = x;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    int el = 10;
    int k = 3;
    int val = 5;
    Node* head = convertArrToLL(arr);
    head = insertBeforeValue(head, el, val);
    print(head);
    
}