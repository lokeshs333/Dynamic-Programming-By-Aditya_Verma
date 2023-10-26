#include <iostream>
using namespace std;

int dp[100][100];

bool knapsack(int num, int weight[], int capacity)
{
    if (capacity == 0)
        return true;
    if (num == 0)
        return false;

    if (dp[num][capacity] != -1)
        return dp[num][capacity];

    // including
    if (weight[num - 1] <= capacity)
        return dp[num][capacity] = knapsack(num - 1, weight, capacity - weight[num - 1]) || knapsack(num - 1, weight, capacity);
    // excluding
    else
        return dp[num][capacity] = knapsack(num - 1, weight, capacity);
}

int main()
{
    int weight[] = {2, 3, 7, 8, 11};
    int capacity = 11;
    int n = 5;
    memset(dp, -1, sizeof(dp));
    bool ans = knapsack(n, weight, capacity);
    cout << "Your answer is " << ans << endl;
    return 0;
}
