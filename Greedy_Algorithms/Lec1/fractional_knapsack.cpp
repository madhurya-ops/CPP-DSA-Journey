#include<iostream>
using namespace std;

struct Item{
int value;
int weight;
};

// custom comparing of values and weights (value / weight)
bool comp(Item val1, Item val2) {
    double r1 = (double)val1.value / val1.weight;
    double r2 = (double)val2.value / val2.weight;
    return r1 > r2;  // Higher value/weight comes first
}

// fractional knapsack
double fractionalKnapsack(Item arr[], int n,int weight){
    sort(arr, arr + n, comp); // sort according to the comp
    double totalVal = 0.0;
    for(int i = 0; i < n; i++){
        if(arr[i].weight <= weight){
            totalVal += arr[i].value;
            weight -= arr[i].weight;
        }
        // in-case only a fraction of the value need to be added in the knapsack
        else{
            totalVal += (double)(arr[i].value / arr[i].weight) * weight;
            break;
        }
    }
    return totalVal;
}

int main(){
Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 50;

    cout << fractionalKnapsack(arr, n, W);
}