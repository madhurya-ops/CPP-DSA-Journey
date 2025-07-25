#include<iostream>
using namespace std;

// Min number of jumps required to reach the last element
// guarentee of reaching the end 
int jump(vector<int>& nums) {
    int jumps = 0;
    int left = 0;
    int right = 0;

    // operating in a range of left -> right
    // left -> min step jump and right -> max step jump
    while(right < nums.size() - 1){
        int farthest = 0;
        for(int ind = left; ind <= right; ind++){
            farthest = max(farthest, ind + nums[ind]);
        }
        jumps++;
        left = right + 1;
        right = farthest;
    }
    return jumps;
}

int main(){
vector<int> nums = {2, 3, 1, 4, 1, 1, 1, 2};
cout << jump(nums);
}