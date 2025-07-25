#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp; //temp arr to store the sorted results
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements are remaining on left side
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    // if elements are remaining on right side
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    // pushing the sorted elements from the temp to orig arr
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

}

void ms(vector<int> &arr, int low, int high){
    if(low >= high){
        return;
    }
    int mid = low + (high - low)/2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    ms(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}