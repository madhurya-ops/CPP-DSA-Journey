#include<iostream>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
        // {diff, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        // keep a dist matrix
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // to traverse the 4-neighbours
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        while(!pq.empty()){
            // extract the top-most element from the PQ
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            // if the destination is reached, return the min diff
            if(row == n - 1 && col == m - 1) return diff;
            
            // traversing the neighbours
            // better dist found for an element in the dist matrix, push in the pq
            // update the dist matrix
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m ){
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]), diff);
                    if(newEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = newEffort;
                        pq.push({dist[nRow][nCol], {nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }

int main(){
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << minimumEffortPath(heights);
}