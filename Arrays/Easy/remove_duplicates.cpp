#include<iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int> &arr, int n){
    int i = 0;
    for(int j = 1; j<n; j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "No. of unique elements = " << removeDuplicate(arr, n);
}