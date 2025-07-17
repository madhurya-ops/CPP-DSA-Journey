#include<iostream>
using namespace std;

int findCelebrity(vector<vector<int>> &matrix){
    int n = matrix.size();
    int top = 0;
    int down = n-1;

    // finding an element that knows no one 
    while(top < down){
        if(matrix[top][down] == 1){
            top++;
        }
        else if(matrix[down][top] == 1){
            down--;
        }
        else{
            top++;
            down--;
        }
    }

    // edge case
    if(top > down){
        return -1;
    }

    // if the above condition is not executed then, top == down
    // check for the entire row and col of 'top' element to ensure if it is a celeb
    for(int i = 0; i < n; i++){
        if(i == top) continue; // ignore the diagonal as no one knows themselves
        if(matrix[top][i] == 0 && matrix[i][top] == 1) continue; // celeb knows no one and n-1 people know him
        else return -1;
    }
    return top;
}

int main(){
    vector<vector<int>> mat = {
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0}
                };
    cout << findCelebrity(mat);

}