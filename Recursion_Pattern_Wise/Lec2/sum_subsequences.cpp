#include<iostream>
using namespace std;

void printS(int ind, vector<int> ds, int sum, int arr[], int s, int n){
    if(ind == n){
        if(s == sum){
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    // pick or take
    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind+1, ds, sum, arr, s, n);

    ds.pop_back();
    s -= arr[ind];

    // not pick or not take
    printS(ind+1, ds, sum, arr, s, n);
}

// To print only one ans
bool printS1(int ind, vector<int> ds, int sum, int arr[], int s, int n){
    if(ind == n){
        // condition satisfied
        if(s == sum){
            for(auto it : ds){
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        // condition not satisfied
        return false;
    }
    // pick or take
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printS1(ind+1, ds, sum, arr, s, n) == true) return true;

    ds.pop_back();
    s -= arr[ind];

    // not pick or not take
    if(printS1(ind+1, ds, sum, arr, s, n) == true) return true;

    return false;
}

// count the number of subsequences with sum = K
int printS2(int ind, int sum, int arr[], int s, int n){
    if(ind == n){
        // condition satisfied
        if(s == sum) return 1;
        // condition not satisfied
        return 0;
    }
    // pick or take
    s += arr[ind];

    int l = printS2(ind+1, sum, arr, s, n);

    s -= arr[ind];

    // not pick or not take
    int r = printS2(ind+1, sum, arr, s, n);

    return l + r;
}

int main(){
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> ds;
    int sum = 2;
    cout << printS2(0, sum, arr, 0, n);
}