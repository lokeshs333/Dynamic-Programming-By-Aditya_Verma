#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
auto start = chrono::high_resolution_clock::now();

int coinChangeWays(int n, vector<int>& coins, int sum) {
    if (sum == 0) {
        return 1;
    }
    if (n == 0 || sum < 0) {
        return 0;
    }
if(dp[n][sum]!=-1)return dp[n][sum];
    // Include the coin at index (n-1) or exclude it
    int includeCoin = coinChangeWays(n, coins, sum - coins[n - 1]);
    int excludeCoin = coinChangeWays(n - 1, coins, sum);

    dp[n][sum]= includeCoin + excludeCoin;
    return dp[n][sum];
}

int main() {
    vector<int> coins = {1, 2, 3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    memset(dp,-1,sizeof(dp));
    int sum = 9;
    int n = coins.size();

    int ways = coinChangeWays(n, coins, sum);

    cout << "Number of ways to make change: " << ways << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
