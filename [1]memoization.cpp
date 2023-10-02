#include<bits/stdc++.h>
using namespace std;

int t[100][100];

int knapsack(vector<int> weight, vector<int> profit, int c, int n) {
    // Base Condition
    if (n == 0 || c == 0)
        return 0;
    if (t[n][c] != -1)
        return t[n][c];

    if (weight[n - 1] <= c)
        return t[n][c] = max(profit[n - 1] + knapsack(weight, profit, c - weight[n - 1], n - 1),
                             knapsack(weight, profit, c, n - 1));
    else
        return t[n][c] = knapsack(weight, profit, c, n - 1);
}

int main() {
    vector<int> weight = {1, 3, 4, 5};
    vector<int> profit = {1, 4, 5, 7};
    int capacity = 7;
    int n = weight.size();

    // Initialize the memoization table with -1
    memset(t, -1, sizeof(t));

    int ans = knapsack(weight, profit, capacity, n);
    cout << "answer is " << ans;

    return 0;
}
