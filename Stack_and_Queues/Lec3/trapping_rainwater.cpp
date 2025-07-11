#include<iostream>
using namespace std;

// amogst lMax and rMax move the one which has a smaller value
// lMax and rMax store the highest value they find in the path
int trap(vector<int>& height) {
    int n = height.size();
    int lMax = 0; int rMax = 0; int total = 0;
    int left = 0;
    int right = n-1;

    while(left < right){
        if(height[left] <= height[right]){
            if(lMax > height[left]){
                total += lMax - height[left];
            }
            else{
                lMax = height[left];
            }
            left++;
        }
        else{
            if(rMax > height[right]){
                total += rMax - height[right];
            }
            else{
                rMax = height[right];
            }
            right--;
        }
    }
    return total;
}

int main(){
vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
cout << trap(height);
return 0;
}