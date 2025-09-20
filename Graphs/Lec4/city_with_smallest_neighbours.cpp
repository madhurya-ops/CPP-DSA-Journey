#include<iostream>
using namespace std;

// solution: using Floyd Warshall Algo
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // create a dist matrix from the given matrix
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(auto it : edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    // populate the dist matrix 
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }

    // traverse one row(city) at a time and store the cnt of it's neighbouring cities
    int cntCity = n;
    int cityNo = -1;
    for(int city = 0; city < n; city++){
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++){
            if(dist[city][adjCity] <= distanceThreshold) cnt++;
        }
        if(cnt <= cntCity){
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}

int main(){
    int n = 4;
    int threshold = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3 ,4},
        {2, 3, 1}
    };
    
    cout << findTheCity(n, edges, threshold);
}