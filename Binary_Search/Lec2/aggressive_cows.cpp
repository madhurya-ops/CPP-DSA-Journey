#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

bool canWePlace(vector<int> &arr, int dist, int cows){
    int n = arr.size();
    int cntCows = 1;
    int last = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] - last < dist){
            cntCows++;
            last = arr[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low = 0;
    int high = arr[n - 1] - arr[0];
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(canWePlace(arr, mid, k) == true){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    // input
    int n;
    cout << "Enter the size of the list: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << aggressiveCows(arr, k);

}