#include<iostream>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st; // to store the ans
    for(int i = 0; i < asteroids.size(); i++){
        if(asteroids[i] > 0){
            st.push_back(asteroids[i]); // pushing the +ve vals
        }
        else{
            // pop the +ve val that is lesser than the -ve (abs)val 
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                st.pop_back(); 
            }
            // pop the equal -ve and +ve (abs)vals
            if(!st.empty() && st.back() == abs(asteroids[i])){
                st.pop_back();
            }
            // if the ds is empty or the top val is -ve, then -ve val will be pushed in the ds
            else if(st.empty() || st.back() < 0){
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
}

int main(){
    vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> ans = asteroidCollision(arr);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}