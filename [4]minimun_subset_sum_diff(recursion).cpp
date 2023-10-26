#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
using namespace std;

auto start = chrono::high_resolution_clock::now();

int minSubsetSumDiff(int n, vector<int>& nums, int csum, int sum) {
    if (n == 0) 
        return abs(sum - csum);

    int includeCurrent = minSubsetSumDiff(n - 1, nums, csum + nums[n - 1], sum-nums[n-1]);
    int excludeCurrent = minSubsetSumDiff(n - 1, nums, csum, sum);
    cout<<csum<<" "<<sum<<endl;
    return min(includeCurrent, excludeCurrent);
}

int main() {
    vector<int> nums = {1, 2, 3, 4,5};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int answer = minSubsetSumDiff(n, nums, 0, sum);
    cout << "Your answer is " << answer << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
