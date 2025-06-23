#include<iostream>
#include<algorithm>
using namespace std;

int maxConsecutiveOnes(vector<int> arr){
    int maxi = 0;
    int count = 0;
    int n = arr.size();
    for(int i = 0; i<n; i++){
        if(arr[i] == 1){
            count++;
            maxi = max(maxi, count);
        }else{
            count = 0;
        }
    }
    return maxi;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    maxConsecutiveOnes(arr);

}