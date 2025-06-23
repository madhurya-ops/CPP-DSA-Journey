#include<iostream>
using namespace std;

int main(){
    int age;
    cin >> age;

    if(age >= 18){
        cout << "Adult";
    }else{
        cout << "Not an adult";
    }

    return 0;
}
