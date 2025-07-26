#include<iostream>
using namespace std;

// Approach: treat the increasing and decresing trend of values as a slope
// Reference: https://www.youtube.com/watch?v=IIqVFvKE6RY
int candy(vector<int>& ratings) {
    int sum = 1;
    int i = 1;
    int n = ratings.size();
    
    while(i < n){
        // fort the plateau top(all values are same) keep the candies to be same 
        if(ratings[i] == ratings[i-1]){
            sum += 1;
            i++;
            continue;
        }
        // for increasing slope, store the peak and increase it with increasing slope
        int peak = 1;
        while(i < n && ratings[i] > ratings[i-1]){
            peak++;
            sum += peak;
            i++;
        }
        // for decreasing slope, store the base and increase it with decreasing slope
        int down = 1;
        while(i < n && ratings[i] < ratings[i-1]){
            sum += down;
            i++;
            down++;
        }
        // at last if down > peak, add their difference to the total sum
        if(down > peak){
            sum += (down - peak);
        }
    }
    return sum;
}

int main(){
vector<int> arr = {1, 0, 2};
cout << candy(arr);
}