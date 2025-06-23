#include<iostream>
#include<algorithm>
using namespace std;

//using xor method
int missingNumXor(vector<int> arr, int k){
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < k; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor2 ^ k;
    return xor1 ^ xor2;
}

// using sum method
int misssingNumber(vector<int> arr, int k){
    int n = arr.size();
    int sum = (k * (k + 1)) / 2;
    int sum2 = 0;
    for(int i = 0; i < n; i++){
        sum2 += arr[i];
    }
    return sum - sum2;
}

int main(){
    // input
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    misssingNumber(arr, k);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}