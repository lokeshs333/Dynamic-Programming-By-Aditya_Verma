
// minimum subset sum difference
#include<bits/stdc++.h>
using namespace std;

auto start = std::chrono::high_resolution_clock::now();

int knapsack(int n, vector<int>& nums, int csum, int sum) {
    
    if (n == 0) return abs(sum - csum);

    int l = knapsack(n-1, nums, csum + nums[n-1], sum - nums[n-1]);
    int r = knapsack(n-1, nums, csum, sum+nums[n-1]);
    return min(l, r);
}

int main() {
vector<int> nums = {1,3,5,7,9,13,16,188,100,12,11,11,2,1,21,21,21,2,1,12,1,1,2,1,21,21};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int answer = knapsack(n, nums, 0, sum);
    cout << "Your answer is " << answer << endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Compilation time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}