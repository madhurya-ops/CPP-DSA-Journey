#include<iostream>
using namespace std;

void findDivisors(int num){
    vector <int> ls;
    for (int i = 0; i*i <= num; i++){
        
        if(num % i == 0){
            ls.push_back(i);
            
            if(num/i != i){
                ls.push_back(num/i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it : ls) cout << it << " ";
}

int main(){
    int num;
    cin >> num;
    findDivisors(num); 
}