#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int knapsack(int n, vector<int>& nums, int sum) {
    if (sum == 0) return 1;
    if (n == 0) return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (nums[n - 1] <= sum)
        dp[n][sum] = knapsack(n - 1, nums, sum - nums[n - 1]) + knapsack(n - 1, nums, sum);
    else
        dp[n][sum] = knapsack(n - 1, nums, sum);

    return dp[n][sum];
}

int main() {
    memset(dp, -1, sizeof(dp)); 
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int n = nums.size();
    int sum = 10;
    int answer = knapsack(n, nums, sum);
    cout << "Your answer is " << answer << endl;
    return 0;
}
