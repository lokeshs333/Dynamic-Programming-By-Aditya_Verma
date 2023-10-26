// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool knapsack(int n, vector<int> &nums, int sum)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    // considering the element
    if (nums[n - 1] <= sum)
    {
        return knapsack(n - 1, nums, sum - nums[n - 1]) || knapsack(n - 1, nums, sum);
    }
    else
    {
        return knapsack(n - 1, nums, sum);
    }
}
int main()
{
    vector<int> nums = {1, 5, 11, 5};
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2 != 0)
    {
        cout << "Not possible to partition into equal sum subsets." << endl;
    }
    else
    {
        int n = nums.size();
        bool answer = knapsack(n, nums, sum / 2);
        cout << "Can be partitioned into equal sum subsets: " << boolalpha << answer << endl;
    }

    return 0;
}
