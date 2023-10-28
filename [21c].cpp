#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int lcs(int n, int m, string a, string b) {
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0)dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
    // If the characters at the current positions match
    if (a[i-1] == b[j-1])
         dp[i][j] = 1 + dp[i-1][j-1];
    else
        // If the characters don't match, take the maximum of two possibilities
         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }


    return dp[n][m];
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
