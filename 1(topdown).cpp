#include <bits/stdc++.h>
using namespace std;
int t[1000][1000];

int knapsack(vector<int> weight, vector<int> profit, int c, int n) {
    // base condition (initialization)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    // bottom-up DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (weight[i - 1] <= j) {
                t[i][j] = max(profit[i - 1] + t[i - 1][j - weight[i - 1]], t[i - 1][j]);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // return the final result
    return t[n][c];
}

int main() {
    vector<int> weight = {1, 3, 4, 5};
    vector<int> profit = {1, 4, 5, 7};
    int capacity = 7;
    int n = weight.size();
    memset(t, -1, sizeof(t));
    int ans = knapsack(weight, profit, capacity, n);
    cout << "Your answer is " << ans;
    return 0;
}
