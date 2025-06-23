#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int sumByD(vector<int> &nums, int div){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + ceil((double)(nums[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    if(n > threshold) return -1;
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(sumByD(nums, mid) <= threshold){
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
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int threshold;
    cout << "Enter the threshold: ";
    cin >> threshold;

    smallestDivisor(nums, threshold);

}