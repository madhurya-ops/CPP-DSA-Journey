#include<iostream>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end){
    // {node, steps}
    queue<pair<int, int>> q;
    q.push({start, 0});

    vector<int> dist(100000, 1e9);
    dist[start] = 0;

    int mod = (int)(1e5);

    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto it : arr){
            int num = (node * it) % mod;
            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                if(num == end) return steps + 1; // return ans
                q.push({num, steps + 1}); // else push in the q
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 75;

    cout << minimumMultiplications(arr, start, end);
}