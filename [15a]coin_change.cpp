#include<bits/stdc++.h>
using namespace std;

auto start = chrono::high_resolution_clock::now();

int coinChangeWays(int n, vector<int>& coins, int sum) {
    if (sum == 0) {
        return 1;
    }
    if (n == 0 || sum < 0) {
        return 0;
    }

    // Include the coin at index (n-1) or exclude it
    int includeCoin = coinChangeWays(n, coins, sum - coins[n - 1]);
    int excludeCoin = coinChangeWays(n - 1, coins, sum);

    return includeCoin + excludeCoin;
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    int n = coins.size();

    int ways = coinChangeWays(n, coins, sum);

    cout << "Number of ways to make change: " << ways << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}



















// not corrected
// //  In the previous version, the mistake was in the condition if (csum == sum) in the recursive function. This condition was checking if the current sum is equal to the target sum, but in the unbounded knapsack problem, you want to include the current coin multiple times, so checking for equality is not appropriate.
// #include <bits/stdc++.h>
// using namespace std;

// auto start = chrono::high_resolution_clock::now();

// int knapsack(int n, vector<int> &nums, int csum, int sum) {
//     if (n == 0) return 0;

//     if (csum == sum) return 1;

//     // Subtract nums[n-1] from csum in the left branch
//     int l = knapsack(n, nums, csum + nums[n - 1], sum);
//     int r = knapsack(n - 1, nums, csum, sum);
//     return l + r;
// }

// int main() {
//     vector<int> coins = {1, 2, 3};
//     int sum = 5;
//     int n = coins.size();

//     int ways = knapsack(n, coins, 0, sum);

//     cout << "Number of ways to make change: " << ways << endl;

//     auto end = chrono::high_resolution_clock::now();
//     chrono::duration<double, milli> duration = end - start;
//     cout << "Execution time: " << duration.count() << " milliseconds" << endl;

//     return 0;
// }







// corrected code
// #include <bits/stdc++.h>
// using namespace std;
// //  In the previous version, the mistake was in the condition if (csum == sum) in the recursive function. This condition was checking if the current sum is equal to the target sum, but in the unbounded knapsack problem, you want to include the current coin multiple times, so checking for equality is not appropriate.
// auto start = chrono::high_resolution_clock::now();

// int unboundedKnapsack(int n, vector<int> &nums, int sum) {
//     if (sum == 0) return 1;
//     if (n == 0) return 0;

//     // Include the current coin in the left branch
//     int l = 0;
//     if (nums[n - 1] <= sum) {
//         l = unboundedKnapsack(n, nums, sum - nums[n - 1]);
//     }

//     // Exclude the current coin in the right branch
//     int r = unboundedKnapsack(n - 1, nums, sum);

//     return l + r;
// }

// int main() {
//     vector<int> coins = {1, 2, 3};
//     int sum = 5;
//     int n = coins.size();

//     int ways = unboundedKnapsack(n, coins, sum);

//     cout << "Number of ways to make change: " << ways << endl;

//     auto end = chrono::high_resolution_clock::now();
//     chrono::duration<double, milli> duration = end - start;
//     cout << "Execution time: " << duration.count() << " milliseconds" << endl;

//     return 0;
// }

