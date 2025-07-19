#include<iostream>
#include <map>
using namespace std;

int fruitIntoBaskets(vector<int> &arr, int k){
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int n = arr.size();
    map<int, int> mpp; // type of digit, freq
    while(right < n){
        mpp[arr[right]]++; // add the elements along with freq in the map
        
        // decrease the freq of the left(num) and erase when it reaches 0
        // increase left by 1
        // also, do not calc maxLen until the map.size() > k
        if(mpp.size() > k){
            mpp[arr[left]]--;
            if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
            left++;
        }

        // calc the max length when map.size() <= k
        if(mpp.size() <= k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main(){
vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
int k = 2;
cout << fruitIntoBaskets(arr, k);
}