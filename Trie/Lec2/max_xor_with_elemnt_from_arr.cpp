#include <iostream>
using namespace std;

// Structure for a trie node
struct Node {
    // Array to hold links to child nodes (0 and 1)
    Node *links[2];

    // Function to check if a child node exists for a given bit
    bool containsKey(int ind) {
        return (links[ind] != NULL);
    }

    // Function to get the child node for a given bit
    Node* get(int ind) {
        return links[ind];
    }

    // Function to create a link to a child node for a given bit
    void put(int ind, Node* node) {
        links[ind] = node;
    }
};

// Class for Trie operations
class Trie {
private:
    // Pointer to the root node
    Node* root;

public:
    // Constructor to initialize the trie
    Trie() {
        root = new Node();
    }

    // Function to insert a number into the trie
    void insert(int num) {
        // Start from root
        Node* node = root;

        // Traverse bits from MSB (31) to LSB (0)
        for (int i = 31; i >= 0; i--) {
            // Extract the current bit
            int bit = (num >> i) & 1;

            // If path for this bit doesn't exist, create it
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }

            // Move to the next node
            node = node->get(bit);
        }
    }

    // Function to find maximum XOR for a given number
    int findMax(int num) {
        // Start from root
        Node* node = root;

        // Variable to store maximum XOR result
        int maxNum = 0;

        // Traverse bits from MSB to LSB
        for (int i = 31; i >= 0; i--) {
            // Extract the current bit
            int bit = (num >> i) & 1;

            // Try to take the opposite bit for maximizing XOR
            if (node->containsKey(!bit)) {
                // Set this bit in the result
                maxNum = maxNum | (1 << i);

                // Move to the opposite branch
                node = node->get(!bit);
            } 
            // If opposite bit doesn't exist, move to same bit branch
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// Class containing the solution logic
class Solution {
public:
    // Function to perform offline max XOR queries
    vector<int> maxXorQueries(vector<int> &arr,
                              vector<vector<int>> &queries) {

        // Result vector to store answers
        vector<int> ans(queries.size(), 0);

        // Vector to store queries in {m, {x, original_index}} format
        vector<pair<int, pair<int,int>>> offlineQueries;

        // Sort the array in ascending order
        sort(arr.begin(), arr.end());

        // Store queries with index for mapping answers later
        int index = 0;
        for (auto &it: queries) {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }

        // Sort queries based on 'm'
        sort(offlineQueries.begin(), offlineQueries.end());

        // Pointer for array traversal
        int i = 0;

        // Size of array
        int n = arr.size();

        // Initialize the trie
        Trie trie;

        // Process each query in sorted order of 'm'
        for (auto &it : offlineQueries) {
            // Insert all elements ≤ m into the trie
            while (i < n && arr[i] <= it.first) {
                trie.insert(arr[i]);
                i++;
            }

            // If trie has at least one element
            if (i != 0)
                ans[it.second.second] = trie.findMax(it.second.first);
            // If no elements ≤ m, return -1
            else
                ans[it.second.second] = -1;
        }
        return ans;
    }
};

// Driver function
int main() {
    // Example array
    vector<int> arr = {3, 10, 5, 25, 2, 8};

    // Display the given array
    cout << "Given Array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Queries in {x, m} format
    vector<vector<int>> queries = {
        {0, 1}, {1, 2}, {0, 3}, {3, 3}
    };

    // Display queries
    cout << "Queries: ";
    for (auto query: queries) {
        cout << query[0] << " " << query[1] << ", ";
    }
    cout << endl;

    // Create solution object
    Solution obj;

    // Get results for queries
    vector<int> result = obj.maxXorQueries(arr, queries);

    // Display results
    cout << "Result of Max XOR Queries:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Query " << i+1 << ": " << result[i] << endl;
    }

    return 0;
}