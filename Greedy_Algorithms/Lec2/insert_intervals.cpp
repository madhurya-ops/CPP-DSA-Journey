#include<iostream>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;
    int n = intervals.size();

    // stores all the non-overlapping intervals in the result
    while(i < n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]);
        i++;
    }

    // adjusts the new interval in the given overlapping intervals
    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    // pushes the new interval in the result
    res.push_back(newInterval);

    // stores all the non-overlapping intervals in the result
    while(i < n){
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

int main(){
vector<vector<int>> intervals = {
    {1, 3},
    {6, 9},    
};
vector<int> newInterval = {2, 5};

vector<vector<int>> ans = insert(intervals, newInterval);
for(auto com : ans){
    for(auto it : com){
        cout << it << " ";
    }
    cout << endl;
}
}