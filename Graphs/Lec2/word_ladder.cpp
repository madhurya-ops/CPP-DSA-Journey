#include<iostream>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord);

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == endWord) return steps;

        // word = hot
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;

                // word exists in the set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList);
    
}