#include<iostream>
using namespace std;

// define the structure of the input array
struct Jobs{
    int id;
    int profit;
    int deadline; 
};

// custom comparing
bool comp(Jobs val1, Jobs val2){
    return val1.profit > val2.profit;
}

pair<int, int> jobSequence(Jobs arr[], int n){
    int totalProfit = 0;
    int cnt = 0;
    int maxDeadline = -1;

    sort(arr, arr + n,comp); // profit in descending order

    // calculate the max deadline in the given input
    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    // create a ds to count and store the job ids assigned 
    vector<int> hash(maxDeadline + 1, -1);

    for(int i = 0; i < n; i++){
        // search backwards for an empty index in the hash (-1) to assign the job for a day
        for(int j = arr[i].deadline; i >= 0; j--){
            if(hash[j] == -1){
                cnt++;
                hash[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    return {cnt, totalProfit};
}

int main(){
    Jobs arr[] = {
        {1, 100, 2},
        {2, 19, 1},
        {3, 27, 2},
        {4, 25, 1},
        {5, 15, 3}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> result = jobSequence(arr, n);
    cout << result.first << ',' << " " << result.second;
}