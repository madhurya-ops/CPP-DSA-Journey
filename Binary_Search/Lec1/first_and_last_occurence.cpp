#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int firstOccurence(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0, high = n - 1;
    int first = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0, high = n - 1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            last = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = firstOccurence(nums, target);
    if(first == -1){
        return {-1, -1};
    }
    int last = lastOccurence(nums, target);
    return {first, last};
}

int main(){
    // input
    int target;
    cout << "Enter the target: ";
    cin >> target;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    searchRange(nums, target);

}