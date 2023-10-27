#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int knapsack(int n, vector<int>& weight, int sum) {
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0) dp[i][j] = INT_MAX-1;
            else if(j==0) dp[i][j] = 0;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(j % weight[i-1] == 0)
                dp[i][j] = j / weight[i-1];
            else
                dp[i][j] = INT_MAX-1;
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=2; j<sum+1; j++){
            if(weight[i-1] <= j){
                dp[i][j] = min(1 + dp[i][j - weight[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> nums = {1,2,3};
    int sum = 5;
    int n = nums.size();
    int answer = knapsack(n, nums, sum);
    cout << "Your answer is " << answer << endl;

    return 0;
}
