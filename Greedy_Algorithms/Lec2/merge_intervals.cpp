#include<iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals; // store the merged Intervals
    if(intervals.size() == 0){
        return mergedIntervals;
    }
    sort(intervals.begin(), intervals.end());
    // to store the interval temporarily before it merges with all the intervals
    vector<int> tempInterval = intervals[0];

    for(auto it : intervals){
        if(it[0] <= tempInterval[1]){
            // comparing the last element of temp and first element of next interval
            // compare till the intervals can't be merged
            tempInterval[1] = max(tempInterval[1], it[1]);
        }
        else{
            mergedIntervals.push_back(tempInterval);
            tempInterval = it; // shift the pointer to the next interval
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

int main(){
vector<vector<int>> intervals = {
    {1, 3}, {2, 6}, {8, 10}, {8, 9}, {9, 11}, {15, 18}, {2, 4}, {16, 17}
};
vector<vector<int>> ans = merge(intervals);

for(auto comp : ans){
    for(auto it : comp){
        cout << it << ", ";
    }
    cout << endl;
}
}