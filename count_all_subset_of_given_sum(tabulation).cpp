// memoization
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int knapsack(int n, vector<int>& nums, int sum) {
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)dp[i][j]=0;
            else if(j==0)dp[i][j]=1;
        }
    }
    dp[0][0]=1;
    int l=0,r=0;
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
return dp[n][sum];
}

int main() {
    memset(dp, -1, sizeof(dp)); 
    vector<int> nums = {1,2,3,4,5,4};
    int n = nums.size();
    int sum = 5;
    int answer = knapsack(n, nums, sum);
    cout << "Your answer is " << answer << endl;

    return 0;
}
