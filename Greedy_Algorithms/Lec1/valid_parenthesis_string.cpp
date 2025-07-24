#include<iostream>
using namespace std;

// '*' -> can be replaced with either '(', ')' or empty char
// opening should be before closing
bool checkValidString(string s) {
    // maintaining a range to check validity
    // if at the end, min == 0 -> valid string 
    int min = 0;
    int max = 0;
    int n = s.size();

    for(int i = 0; i < n; i++){
        // for '(' -> +1
        if(s[i] == '('){
            min += 1;
            max += 1;
        }
        // for ')' -> -1
        else if(s[i] == ')'){
            min -= 1;
            max -= 1;
        }
        // range of '*' -> -1 to +1, therfore min - 1 and max + 1
        else{
            min = min - 1;
            max = max + 1;
        }
        // reset min to 0 when min < 0 to maintain the range 
        if(min < 0) min = 0;
            
        if(max < 0) return false;
    }
    return (min == 0);
}

int main(){
string s = "()*)*()";
cout << checkValidString(s);
}