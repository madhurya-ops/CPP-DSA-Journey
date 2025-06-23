#include<iostream>
#include<math.h>
using namespace std;

int chceckArmstrong(int x){
    int dup = x;
    int sum = 0;

    int n = 0;
    int temp = x;
    while(temp != 0){
        temp = temp/10;
        n++;
    }

    temp = x;
    while(temp != 0){
        int lastDig = temp % 10;
        sum = sum + pow(lastDig, n);
        temp = temp/10;
    }

    if(dup == sum){
        cout << "It is an Armstrong number";
    }else{
        cout << "It is not an Armstrong number";
    }

}
 
int main(){
    chceckArmstrong(9474);
}