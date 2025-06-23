#include<iostream>
#include<map>
#include<algorithm>
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
    
int countPairs(vector<int> &nums, int low, int mid, int high){
    int count = 0;
    int right = mid + 1;
    for(int i = low; i <= mid; i++){
        while(right <= high && nums[i] > 2LL * nums[right]) right++;
        count += (right - (mid + 1));
    }
    return count;
}

int ms(vector<int> &arr, int low, int high){
    int count = 0;
    if(low >= high)return count;
    int mid = low + (high - low)/2;
    count += ms(arr, low, mid);
    count += ms(arr, mid+1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << ms(nums, 0, n-1);

}