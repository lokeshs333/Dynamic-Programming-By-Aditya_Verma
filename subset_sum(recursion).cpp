#include <iostream>
using namespace std;
bool knapsack(int n, int weight[], int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    // include
    if (weight[n - 1] <= sum)
        return knapsack(n - 1, weight, sum - weight[n - 1]) || knapsack(n - 1, weight, sum);
    // excluding
    else
        return knapsack(n - 1, weight, sum);
}
int main()
{
    int weight[] = {2, 3, 7, 8, 10};
    int sum = 11;
    memset(dp, -1, sizeof(dp));
    bool ans = knapsack(5, weight, sum);
    cout << "your answer is " << ans;
}
