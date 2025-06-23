#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k) {
    if(n1 > n2) return findMedianSortedArrays(nums2, nums1, n2, n1, k);
    int low = max(k - n2, 0), high = min(k, n1);
    int left = k;
    int n = n1 + n2;
    while(low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 -1];
        if(l1 <= r2 && l2 <= r1){
            max(l1,l2);
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main(){
    // input
    int n1;
    cout << "Enter the size of the list: ";
    cin >> n1;
    vector<int> nums1(n1);
    for(int i = 0; i < n1; i++){
        cin >> nums1[i];
    }
    int n2;
    cout << "Enter the size of the list: ";
    cin >> n2;
    vector<int> nums2(n2);
    for(int i = 0; i < n2; i++){
        cin >> nums2[i];
    }
    int k;
    cout << "Value of k: ";
    cin >> k;

    cout << findMedianSortedArrays(nums1, nums2, n1, n2, k);

}