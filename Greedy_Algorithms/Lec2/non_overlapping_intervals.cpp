#include<iostream>
using namespace std;
// inverse of the N-meetings in a room
// calc the number of non-overlapping intervals
// return the difference of n and non-overlapping intervals

// custom comp
 bool comp(vector<int> &val1, vector<int> &val2){
    return val1[1] < val2[0];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if(n == 0) return 0;

    // sorting on the basis of the end-time
    sort(intervals.begin(), intervals.end(), comp);

    int cnt = 1;
    int lastEndTime = intervals[0][1];

    for(int i = 1; i < n; i++){
        if(intervals[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return n - cnt;
    }

int main(){
vector<vector<int>> intervals {
    {1, 2}, {1, 2}, {1, 2}
};

cout << eraseOverlapIntervals(intervals);
}