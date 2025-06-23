#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low + k;
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
    cout << "Enter k: ";
    cin >> k;

    cout << findKthPositive(arr, k);

}