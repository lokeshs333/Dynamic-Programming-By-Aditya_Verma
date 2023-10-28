#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

// Function to calculate the length of the Longest Common Subsequence
int lcs(int n, int m, string a, string b) {
    if (n == 0 || m == 0) return 0;
    
    // If the value is already computed, return it
    if (dp[n][m] != -1) return dp[n][m];

    // If the characters at the current positions match
    if (a[n-1] == b[m-1])
        return dp[n][m] = 1 + lcs(n-1, m-1, a, b);
    else
        // If the characters don't match, take the maximum of two possibilities
        return dp[n][m] = max(lcs(n-1, m, a, b), lcs(n, m-1, a, b));
}

int main() {
    memset(dp, -1, sizeof(dp));
    string a = "abcdgh";
    string b = "abedfhr";
    int n = a.size();
    int m = b.size();
    int ans = lcs(n, m, a, b);
    cout << "The length of the Longest Common Subsequence is " << ans << endl;
    return 0;
}
