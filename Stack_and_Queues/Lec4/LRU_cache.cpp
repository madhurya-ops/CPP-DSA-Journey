#include<iostream>
using namespace std;


// Least Recently Used Cache
// Cache: DLL, Ds: unordered map
class LRUCache {
public:
// Defining a node
    class Node{
        public: 
            int key;
            int val;
            Node *next;
            Node *prev;
            Node(int _key, int _val){
                val = _val;
                key = _key;
            }
    };

    // head and tail store all the val and key b/w them
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mpp; // int, node reference

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    // add a new node after the head and connect the pointers 
    void addNode(Node* newNode){
        Node* currentNode = head -> next;
        head -> next = newNode;
        newNode -> next = currentNode;
        newNode -> prev = head;
        currentNode -> prev = newNode;
    }

    // delete a node, i.e rearrange the pointers
    void deleteNode(Node* delNode){
        Node* prevNode = delNode -> prev;
        Node* afterNode = delNode -> next;

        prevNode -> next = afterNode;
        afterNode -> prev = prevNode;
    }
    
    // display the value for the key given
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;

        // store the reference of the node and display it's value, 
        // also bring the node to the fornt of the DLL
        Node* resNode = mpp[key];
        int res = resNode -> val;
        mpp.erase(key);
        deleteNode(resNode);
        addNode(resNode);
        mpp[key] = head -> next;
        return res;
    }
    
    // put the given key, val in the map as well as the DLL
    void put(int key, int value) {
        // if the same key already exists in the map, just change the val
        if(mpp.find(key) != mpp.end()){
            Node* existingNode = mpp[key];
            mpp.erase(key);
            deleteNode(existingNode);
        }
        // if capacity reached, delete the last node(tail -> prev)
        if(mpp.size() == cap){
            mpp.erase(tail -> prev -> key);
            deleteNode(tail ->prev);
        }

        // add the new node to the front of the DLL
        addNode(new Node(key, value));
        mpp[key] = head -> next;
    }
};