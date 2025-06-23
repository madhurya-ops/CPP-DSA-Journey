#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int findMax(vector<int> &piles){
    int maxi = INT_MIN;
    int n = piles.size();
    for(int i = 0; i < n; i++){
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

long long calcTotalHours(vector<int> &piles, int hourly){
    long long totalH = 0;
    int n = piles.size();
    for(int i = 0; i < n; i++){
        totalH += ceil((double)piles[i] / (double)hourly);
    }
    return totalH;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = findMax(piles);
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        long long totalH = calcTotalHours(piles, mid);
        if(totalH <= h){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int main(){
    // input
    int n;
    cout << "Enter the size of the list: ";
    cin >> n;
    vector<int> piles(n);
    for(int i = 0; i < n; i++){
        cin >> piles[i];
    }
    int h;
    cout << "Enter the number of hours: ";
    cin >> h;

    minEatingSpeed(piles, h);

}