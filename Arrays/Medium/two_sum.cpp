#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

// variety-1 (yes/no)
bool twoSum(vector<int> arr, int target){
    int left = 0;
    int right = 0;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            return 'Yes';
        }else if(sum < target){
            left++;
        }else{
            right --;
        }
    }
    return 'No';
}

// variety-2 ([i, j])
vector<int> TwoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(mpp.find(moreNeeded) != mpp.end()){
                return {i, mpp[moreNeeded]};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }

int main(){
    // input
    long long target;
    cin >> target;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    twoSum(arr, target);

}