#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
#include<queue>
using namespace std;

// using bs

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double MinimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

// using priority-queue
// TC -> O(NlogN + KlogN)
// SC -> O(N - 1)
long double MinimiseMaxDist(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;
    for(int i = 0; i < n - 1; i++){
        pq.push({arr[i + 1] - arr[i], i});
    }
    for(int gasStations = 1; gasStations <= k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double) (howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}

// brute-force
long double minimiesMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    for(int gasStations = 1; gasStations <= k; gasStations++){
        long double maxSection = -1;
        int maxInd = -1;
        for(int i = 0; i < n - 1; i++){
            long double diff = (arr[i + 1] - arr[i]);
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    long double maxAns = -1;
    for(int i = 0; i < n - 1; i++){
        long double diff = (arr[i + 1] - arr[i]);
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns; 
}

int main(){
    // input
    int n;
    cout << "Enter the size of the list: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Value of k: ";
    cin >> k;

    cout << minimiesMaxDistance(arr, k);

}