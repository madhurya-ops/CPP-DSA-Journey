#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

// Moore's voting algorithm
int majorityElement(vector<int>& nums) {
        int count = 0;
        int el;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count = 1;
                el = nums[i];
            }else if(nums[i] == el){
                count++;
            }else{
                count--;
            }
        }
        int count1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el){
                count1++;
            }
        }
        if(count1 > (nums.size() / 2)){
            return el;
        }
        return -1;
    }

int main(){
    // input
    long long target;
    cin >> target;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << majorityElement(nums);

}