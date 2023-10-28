#include <bits/stdc++.h>
using namespace std;

// Declare a 2D array for memoization
int dp[1001][1001];

int lcs(int n, int m, string a, string b) {
    // Base case
    if (n == 0 || m == 0)
        return 0;

    // Check if the result is already calculated
    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
        return dp[n][m] = 1 + lcs(n - 1, m - 1, a, b);
    else
        return dp[n][m] = 0;
}

int main() {
    string a = "abcde";
    string b = "abcd";
    int n = a.size();
    int m = b.size();

    // Initialize the dp array with -1
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, lcs(i, j, a, b));
        }
    }

    cout << "The length of the Longest Common substring is " << ans << endl;
    return 0;
}
