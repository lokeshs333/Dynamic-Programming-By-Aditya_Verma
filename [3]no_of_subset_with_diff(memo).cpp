#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int knapsack(int n, vector<int>& nums, int csum, int sum, int diff) {
    if (csum + diff == sum) return 1;
    if (n == 0) return 0;
    if(dp[n][csum]!=-1)return dp[n][csum];
      int l = knapsack(n - 1, nums, csum + nums[n - 1], sum, diff) + knapsack(n - 1, nums, csum, sum, diff);
        int r = knapsack(n - 1, nums, csum, sum, diff);
        dp[n][csum]=max(l , r);
    return dp[n][csum];
}

int main() {
    vector<int> nums = {1, 1, 2, 3};
    int n = nums.size();
    memset(dp,-1,sizeof(dp));
    int sum = 0;
    for (auto it : nums) sum += it;
    int diff = 3;
    int answer = knapsack(n, nums, 0, sum, diff);
    cout << "Your answer is " << answer << endl;

    return 0;
}
