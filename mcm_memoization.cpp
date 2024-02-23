#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int mn = INT_MAX;

int mcm(vector<int> &nums, int i, int j) {
    if (i >= j) return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    for (int k = i; k <= j - 1; k++) {
        int tempans = mcm(nums, i, k) + mcm(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j];
        if (tempans < mn) mn = tempans;
    }

    return dp[i][j]= mn;
}

int main() {
    vector<int> nums = {40, 20, 30, 10, 30};
    memset(dp,-1,sizeof(dp));
    int ans = mcm(nums, 1, nums.size() - 1);
    cout << ans;
    return 0;
}
