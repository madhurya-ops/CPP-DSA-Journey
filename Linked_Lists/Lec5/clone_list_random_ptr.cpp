#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node* random;

    public:
    Node(int data1, Node* next1, Node* back1, Node* random1){
        data = data1;
        next = next1;
        back = back1;
        random = random1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

// Convert linked list to [[val, random_index]] format
vector<vector<string>> toInputFormat(Node* head) {
    unordered_map<Node*, int> index;
    vector<Node*> nodes;
    for (Node* cur = head; cur; cur = cur->next)
        index[cur] = nodes.size(), nodes.push_back(cur);

    vector<vector<string>> res;
    for (Node* node : nodes)
        res.push_back({to_string(node->data), node->random ? to_string(index[node->random]) : "null"});
    return res;
}

// Print the Linked-List
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert copyNode in between the nodes
void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = temp->next->next;
    }
}

// Connet random pointers
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copy = temp->next;
        if(temp->random) copy->random = temp->random->next;
        else copy->random = nullptr;
        temp = temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* dNode = new Node(-1);
    Node* res = dNode;
    Node* temp = head;
    while(temp != NULL){
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }
    return dNode->next;
}

// Returning the clone
Node* copyRandomList(Node* head) {
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
}

int main(){
    // Build the original list (same as the image)
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Set random pointers
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    // Deep copy the list
    Node* copied = copyRandomList(n1);

    // Print input-style output of copied list
    vector<vector<string>> formatted = toInputFormat(copied);
    cout << "[";
    for (int i = 0; i < formatted.size(); ++i) {
        cout << "[" << formatted[i][0] << "," << formatted[i][1] << "]";
        if (i != formatted.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}