#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

int findDays(vector<int> &weights, int cap){
    int days = 1, load = 0;
    for(int i = 0; i < weights.size(); i++){
        if(weights[i] + load > cap){
            days = days + 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        int NoOfD = findDays(weights, mid);
        if(NoOfD <= days){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    // input
    int n;
    cout << "Enter the size of the list: ";
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    int days;
    cout << "Enter the days: ";
    cin >> days;

    shipWithinDays(weights, days);

}