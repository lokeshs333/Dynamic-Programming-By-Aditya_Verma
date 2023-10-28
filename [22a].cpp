#include<bits/stdc++.h>
using namespace std;

int lcs(int n, int m, string a, string b) {
    // Base case
    if (n == 0 || m == 0)
        return 0;

    if (a[n - 1] == b[m - 1])
        return 1 + lcs(n - 1, m - 1, a, b);
    else
        return 0;
}

int main() {
    string a = "abcde";
    string b = "abcd";
    int n = a.size();
    int m = b.size();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, lcs(i, j, a, b));
        }
    }

    cout << "The length of the Longest Common substring is " << ans << endl;
    return 0;
}
