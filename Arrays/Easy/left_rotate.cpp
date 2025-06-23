#include<iostream>
using namespace std;
// optimal
void LeftRotate(int arr[], int n, int d){
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

// bruteforce
void leftRotate(int arr[], int n, int d){
    // time the array will be rotated
    d = d % n;

    int temp[d];
    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }

    //shifting
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }

    //put back temp
    for(int i = n-d; i < n; i++){
        arr[i] = temp[i - (n - d)];
    }
}

int main(){
    // input
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int d;
    cin >> d;
    LeftRotate(arr, n, d);

    //output
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    
}