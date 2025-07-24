#include<iostream>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    // to store the denominations of 5, 10
    int five = 0;
    int ten = 0;
    int n = bills.size();

    // cost of one lemonade = $5
    for(int i = 0; i < n; i++){
        // no change to be paid back when $5 received
        if(bills[i] == 5){
            five += 1;
        }
        // when $10 received, return 5
        else if(bills[i] == 10){
            if(five){
                five -= 1;
                ten += 1;
            }
            else return false;
        }
        // when $20 received, return back $15, either in 10+5 or 5+5+5 denominations
        else{
            if(five > 0 && ten > 0){
                five -= 1;
                ten -= 1;
            }
            else if(five >= 3){
                five -= 3;
            }
            else return false;
        }
    }
    return true;
} 

int main(){
vector<int> bills = {5, 5, 5, 10, 20};
cout << lemonadeChange(bills);
}