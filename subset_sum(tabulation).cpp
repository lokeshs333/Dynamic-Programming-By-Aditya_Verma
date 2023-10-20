
#include <iostream>
using namespace std;
int dp[100][100];
bool knapsack(int n, int weight[], int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            if (i == 0)
                dp[i][j] = false;
        }
    }
    dp[0][0] = true;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            // include
            if (weight[n - 1] <= sum)
                dp[i][j] = dp[i - 1][j - weight[i - 1]] || dp[i - 1][j];
            // excluding
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int weight[] = {2, 3, 7, 8, 10};
    int sum = 11;
    memset(dp, -1, sizeof(dp));
    bool ans = knapsack(5, weight, sum);
    cout << "your answer is " << ans;
}
