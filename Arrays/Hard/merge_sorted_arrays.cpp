#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//optimal-1
void merge1(long long nums1[], long long nums2[], int n, int m){
    int left = n - 1;
    int right = 0;
    while(left >= 0 && right < m){
        if(nums1[left] > nums2[right]){
            swap(nums1[left], nums2[right]);
            left--, right++;
        }
        else{
            break;
        }
    }
    sort(nums1, nums1 + n);
    sort(nums2, nums2 + m);
}

// optimal-2: using gap method(Shell sort)
void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
    if(nums1[ind1] > nums2[ind2]){
        swap(nums1[ind1], nums2[ind2]);
    }
}
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = (m + n);
    int gap = (len / 2) + (len % 2);
    while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // arr1 and arr2
            if(left < m && right >= m){
                swapIfGreater(nums1, nums2, left, right - m);
            }
            // arr2 and arr2
            else if(left >= m){
                swapIfGreater(nums1, nums2, left - m, right - m);
            }
            // arr1 and arr1
            else{
                swapIfGreater(nums1, nums2, left, right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

// optimal-3 (both the arrays merged into the first with empty spaces)
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;          
    int j = n - 1;          
    int k = m + n - 1;      

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

       
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    } 
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums1(n);
    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }
    int m;
    cin >> m;
    vector<int> nums2(m);
    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }

    merge2(nums1, n, nums2, m);

}