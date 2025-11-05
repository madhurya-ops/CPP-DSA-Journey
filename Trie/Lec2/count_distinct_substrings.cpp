#include<iostream>
using namespace std;

struct Node{
    Node* links[26];

    bool containsKey(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &word){
    int cnt = 0;
    Node* root = new Node();

    for(int i = 0; i < word.size(); i++){
        Node* node = root;
        for(int j = i; j < word.size(); j++){
            if(!node -> containsKey(word[j])){
                cnt++;
                node -> put(word[j], new Node());
            }
            node = node -> get(word[j]);
        }
    }
    return cnt + 1;
}

int main() {
    vector<string> operations = {"countDistinctSubstrings"};
    vector<vector<string>> inputs = {{"ababa"}};

    vector<string> output;

    for (int i = 0; i < operations.size(); i++) {
        string op = operations[i];

        if (op == "countDistinctSubstrings") {
            string s = inputs[i][0];
            int result = countDistinctSubstrings(s);
            output.push_back(to_string(result));
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