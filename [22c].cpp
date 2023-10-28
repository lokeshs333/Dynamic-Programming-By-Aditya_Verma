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
         dp[i][j] = 0;
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    string a = "abcde";
    string b = "abcd";
    int n = a.size();
    int m = b.size();
    int ans = lcs(n, m, a, b);
    cout << "The length of the Longest Common substring is " << ans << endl;
    return 0;
}
