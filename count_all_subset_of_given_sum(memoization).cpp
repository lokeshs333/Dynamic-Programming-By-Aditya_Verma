
#include<bits/stdc++.h>
using namespace std;

int dp[101][1001]; // Adjust array size as per constraints

auto start = std::chrono::high_resolution_clock::now();

int knapsack(int n, vector<int>& nums, int sum) {
    // Base case
    if (sum == 0)
        return 1;
    
    // Base case: If n is 0 and sum is not 0, there is no subset
    if (n == 0)
        return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    // Taking element
    int left = 0;
    if (nums[n - 1] <= sum)
        left = knapsack(n - 1, nums, sum - nums[n - 1]);

    // Not taking the element
    int right = knapsack(n - 1, nums, sum);

    dp[n][sum] = left + right;

    return dp[n][sum];
}

int main() {
    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1

    vector<int> nums = {2, 3, 5, 6, 8, 10};
    int n = nums.size();
    int sum = 10;
    int answer = knapsack(n, nums, sum);
    cout << "Your answer is " << answer << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Compilation time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
