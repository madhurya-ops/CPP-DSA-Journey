#include<iostream>
using namespace std;

// solving using the BFS algo
// calculating min dist to a 0 from each element
// No diagonal dist is calculated
// min dist for a '0' is 0 (because it is closest to itself)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0)); // vis matrix
    vector<vector<int>> dist(n, vector<int>(m, 0)); // distance matrix
    queue<pair<pair<int, int>, int>> q; //{{row, col}, steps}

    // filling up the queue
    // initially, inserting all zeroes with step size of 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps; // update the steps in the dist matrix
        
        // traversing all the neighbouring nodes
        // marking them visited, if != vis
        // if visited, then do not add in the q
        // adding all the non-visited neighbours in the queue with step size
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
            }
        }
    }
        
    return dist; // return the dist matrix
}

int main(){
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> ans = updateMatrix(mat);

    for(auto comp : ans){
        for(auto it : comp){
            cout << it << " ";
        }
        cout << endl;
    }
}