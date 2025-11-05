#include <iostream>
using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};


class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            // moves to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    vector<string> operations = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> inputs = {
        {}, {"apple"}, {"apple"}, {"app"}, {"app"}, {"app"}, {"app"}
    };

    Trie* obj = nullptr;
    vector<string> output;

    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];

        if (op == "Trie") {
            obj = new Trie();
            output.push_back("null");
        } 
        else if (op == "insert") {
            obj->insert(inputs[i][0]);
            output.push_back("null");
        } 
        else if (op == "search") {
            bool res = obj->search(inputs[i][0]);
            output.push_back(res ? "true" : "false");
        } 
        else if (op == "startsWith") {
            bool res = obj->startsWith(inputs[i][0]);
            output.push_back(res ? "true" : "false");
        }
    }

    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}