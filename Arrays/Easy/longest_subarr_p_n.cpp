#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int longestSubArr(vector<int> arr, long long k){
    map<long long, int> preSumMap;
    int maxLen = 0;
    int sum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
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