#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k){
        int count = 0;
        int NoOfBouquet = 0;
        int n = bloomDay.size();
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                NoOfBouquet += (count / k);
                count = 0;
            }
        }
        NoOfBouquet += (count / k);
        return NoOfBouquet >= m;   
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()) return -1;
        int mini = INT_MAX, maxi = INT_MAX;
        for(int i = 0; i < bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)){
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
    vector<int> bloomDay(n);
    for(int i = 0; i < n; i++){
        cin >> bloomDay[i];
    }
    int m;
    cout << "Enter the value of m: ";
    cin >> m;
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    minDays(bloomDay, m, k);

}