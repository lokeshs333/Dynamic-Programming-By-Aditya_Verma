#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
auto start = chrono::high_resolution_clock::now();

int minSubsetSumDiff(int n, vector<int>& nums, int csum, int sum) {
    if (n == 0) 
        return abs(sum - csum);
        if(dp[n][csum]!=-1)return dp[n][csum];
    int includeCurrent = minSubsetSumDiff(n - 1, nums, csum + nums[n - 1], sum-nums[n-1]);
    int excludeCurrent = minSubsetSumDiff(n - 1, nums, csum, sum);
     dp[n][csum]= min(includeCurrent, excludeCurrent);
    return dp[n][csum];
}

int main() {
    vector<int> nums = {1, 2, 3, 4 ,100};
    memset(dp,-1,sizeof(dp));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int answer = minSubsetSumDiff(n, nums, 0, sum);
    cout << "Your answer is " << answer << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
