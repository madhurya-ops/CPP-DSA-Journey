#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int> &arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        qs(arr, low, partitionIndex - 1);
        qs(arr, partitionIndex + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    qs(arr, 0, arr.size() - 1);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}