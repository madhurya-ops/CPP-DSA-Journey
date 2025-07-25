#include<iostream>
using namespace std;

// Approach: Two-pointer / Greedy
// for the given arrival and departure times, 
// find the min stations required for all the trains to stop
int minRailStations(vector<int> &arrival, vector<int> &depart){
    int n = arrival.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxCnt = 0;

    // sort both the arrays 
    sort(arrival.begin(), arrival.end());
    sort(depart.begin(), depart.end());

    while(i < n){
        // increase the counter if the arrival pointer moves
        if(arrival[i] <= depart[j]){
            cnt++;
            i++;
        }
        // decrease the counter if the depart pointer moves
        else{
            cnt--;
            j++;
        }
        // store the max count of stations occupied at once
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main(){
vector<int> arrival = {900, 945, 955, 1100, 1500, 1800};
vector<int> depart = {920, 1200, 1130, 1150, 1900, 2000};
cout << minRailStations(arrival, depart);
}