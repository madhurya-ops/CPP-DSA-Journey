#include<iostream>
#include<map>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

int countStudents(vector<int> &arr, int pages){
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

int findPages(vector<int> &arr, int students){
    if(students > arr.size()) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        int NoOfStud = countStudents(arr, mid);
        if(NoOfStud > students){
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
    int students;
    cout << "Number of students: ";
    cin >> students;

    cout << findPages(arr, students);

}