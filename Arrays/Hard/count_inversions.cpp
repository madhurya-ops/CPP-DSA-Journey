#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp; //temp arr to store the sorted results
    int left = low;
    int right = mid + 1;
    int count = 0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            count += (mid - left + 1); // increasing the count when left > right
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
    return count;
}

int ms(vector<int> &arr, int low, int high){
    int count = 0;
    if(low >= high){
        return count;
    }
    int mid = low + (high - low)/2;
    count += ms(arr, low, mid);
    count += ms(arr, mid+1, high);
    count += merge(arr, low, mid, high); // merging sorted halves
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