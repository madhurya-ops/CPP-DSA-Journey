#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

//variety-1 (number of positive and negative values are equal)
vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0;
        int negIndex = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans; 
    }

// variety-2 (number of positive and negative values are not equal)
vector<int> alternateNumbers(vector<int> nums){
    int n = nums.size();
    vector<int> pos, neg;
    for(int i = 0; i < n; i++){
        if(nums[i] > 0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        int index = 2*neg.size();
        for(int i = neg.size(); i < pos.size(); i++){
            nums[index] = pos[i];
            index++;
        }
    }else{
        for(int i = 0; i < pos.size(); i++){
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        int index = 2*pos.size();
        for(int i = pos.size(); i < neg.size(); i++){
            nums[index] = neg[i];
            index++;
        }
    }
    return nums;
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

   rearrangeArray(nums);

   for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
   }

}