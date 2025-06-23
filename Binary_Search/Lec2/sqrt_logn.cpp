#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int floorSqrt(int num) {
    int low = 1;
    int high = num;
    int ans = 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if((mid * mid) <= num){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main(){
    // input
    int num;
    cout << "Enter the number: ";
    cin >> num;

    cout << floorSqrt(num);

}