#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

// this code works on the concept of min[max] i.e min of max
// this solution works for painter's partition/ allocate-books/ split array largest sum 

int countK(vector<int> &arr, int pages){
    int stud = 1;
    int pagesCount = 0;
    for(int i = 0; i < arr.size(); i++){
        if(pagesCount + arr[i] <= pages){
            pagesCount += arr[i];
        }
        else{
            stud++;
            pagesCount = arr[i];
        }
    }
    return stud;
}

int findPages(vector<int> &arr, int k){
    if(k > arr.size()) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        int NoOfStud = countK(arr, mid);
        if(NoOfStud > k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
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

    cout << findPages(arr, k);

}