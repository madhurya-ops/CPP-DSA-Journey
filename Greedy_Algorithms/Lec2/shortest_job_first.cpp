#include<iostream>
using namespace std;

long SJF(vector<int> &arr){
    int time = 0;
    int waitTime = 0;
    int n = arr.size();

    // sort the jobs to do the shortest job first
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        waitTime += time;
        time += arr[i];
    }
    return (waitTime/n); // average wait time
}

int main(){
vector<int> arr = {4, 3, 7, 1, 2};
cout << SJF(arr);
}