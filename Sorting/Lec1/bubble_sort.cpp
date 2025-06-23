#include<iostream>
using namespace std;

void swap(int arr[], int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
}

void bubble_sort(int arr[], int n){
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j <= i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
        
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}