#include<iostream>
using namespace std;

void findPrime(int num){
    int count = 0;
    for (int i = 0; i*i <= num; i++){
        
        if(num % i == 0){
            count++;
            
            if(num/i != i){
                count++;
            }
        }
    }
    if(count == 2){
        cout << "It is a prime number";
    }else{
        cout << "It is not a prime number";
    }
}

int main(){
    int num;
    cin >> num;
    findPrime(num); 
}