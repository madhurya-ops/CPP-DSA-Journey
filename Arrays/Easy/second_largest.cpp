#include<iostream>
using namespace std;

void secondLargest(int arr[], int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        } else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    cout << "Second lrgest element in the array is: "<< slargest;
}

int main(){
    // input
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    secondLargest(arr, n);

}