#include <iostream>
#include <cstddef>
using namespace std;

// Node structure for Trie
class Node {
public:
    Node* links[2];

    // Check if bit path exists
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    // Get the child node for bit
    Node* get(int bit) {
        return links[bit];
    }

    // Create a link for the bit
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Solution {
public:
    Node* root;

    // Initialize root node
    Solution() {
        root = new Node();
    }

    // Insert a number into the Trie
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            // Get the i-th bit
            int bit = (num >> i) & 1;

            // Create path if it doesn't exist
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            // Move to next node
            node = node->get(bit);
        }
    }

    // Get max XOR for a given number
    int getMaxXOR(int num) {
        Node* node = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            // Get the i-th bit
            int bit = (num >> i) & 1;

            // Try to go opposite bit to maximize XOR
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxXor;
    }

    // Find the maximum XOR among all pairs
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums) {
            insert(num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, getMaxXOR(num));
        }

        return maxResult;
    }
};

// Driver code
int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution sol;
    cout << sol.findMaximumXOR(nums) << endl;
    return 0;
}