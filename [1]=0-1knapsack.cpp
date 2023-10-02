#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight, vector<int> profit, int c, int n)
{
    // Base Condition
    if (n == 0 || c == 0)
        return 0;

    if (weight[n - 1] <= c)
        return max(profit[n - 1] + knapsack(weight, profit, c - weight[n - 1], n - 1), knapsack(weight, profit, c, n - 1));

    else if (weight[n - 1] > c)
        knapsack(weight, profit, c, n - 1);
}
int main()
{
    vector<int> weight = {1, 3, 4, 5};
    vector<int> profit = {1, 4, 5, 7};
    int capacity = 7;
    int n = weight.size();
    int ans = knapsack(weight, profit, capacity, n);
    cout << "answer is " << ans;
    return 0;
}