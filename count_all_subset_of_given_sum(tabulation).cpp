#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, vector<int>& nums, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // Base case initialization
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Build the dp table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            // If the current element is less than or equal to the sum,
            // consider both including and excluding the element
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            // If the current element is greater than the sum,
            // only consider excluding the element
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int n = nums.size();
    int sum = 10;
    int answer = knapsack(n, nums, sum);
    cout << "Your answer is " << answer << endl;

    return 0;
}
