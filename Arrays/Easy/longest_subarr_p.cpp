#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int longestSubArr(vector<int> arr, long long k){
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = arr[0];
    int n = arr.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n){
            sum += arr[right];
        }
    }
    return maxLen;
}

int main(){
    // input
    long long k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << longestSubArr(arr, k);

}