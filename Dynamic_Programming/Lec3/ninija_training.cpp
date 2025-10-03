#include<iostream>
using namespace std;

// Recursive approach
int f1(int day, int last, vector<vector<int>> &points){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = points[day][task] + f1(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

// memoized approach
int f2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];
    

    int maxi = 0;
    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = points[day][task] + f2(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

// tabulation approach
int f3(int n, vector<vector<int>> &points, vector<vector<int>> &dp){
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for(int day = 1; day < n; day++){
        for(int last = 0; last < 4; last++){
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

// space optimized approach
int f4(int n, vector<vector<int>> &points, vector<int> &prev){
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for(int day = 1; day < n; day++){
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++){
            temp[last] = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

int main(){
    vector<vector<int>> points = {
        {10, 50, 1},
        {5, 100, 11},
    };
    int n = points.size();

    // vector<vector<int>> dp(n, vector<int>(4, -1));
    vector<int> dp(4, -1);

    cout << f4(n, points, dp);
}