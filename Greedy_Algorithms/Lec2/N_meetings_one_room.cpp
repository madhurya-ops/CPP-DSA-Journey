#include<iostream>
using namespace std;

// struct to store start,end & pos, all in a single entry and in one instance 
struct Data{
int start;
int end;
int pos;
};

// custom comp to sort on the basis of increasing end time
bool comp(Data val1, Data val2){
    return val1.end <val2.end;
}

int meetingSchedule(vector<int> &start, vector<int> &end, int n){
    // store start, end, pos of a meeting in the array -> arr
    vector<Data> arr(n);
     for(int i = 0 ; i < n; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
     }

    // sort the arr using custom comp
     sort(arr.begin(), arr.end(), comp);

     int cnt = 1;
     int freeTime = arr[0].end; // time when the meeting is over
     vector<int> ds = {arr[0].pos}; // storing the pos and the order of meetings

    // selecting the max meetings that can happen
     for(int i = 1; i < n; i++){
        if(arr[i].start > freeTime){
            cnt++;
            freeTime = arr[i].end;
            ds.push_back(arr[i].pos);
        }
     }
    return ds.size(); // returning the number of meetings
    // can also return the order of meetings
}

int main(){
vector<int> start = {0, 3, 1, 5, 5, 8};
vector<int> end = {5, 4, 2, 9, 7, 9};
int n = start.size();

cout << meetingSchedule(start, end, n);
}