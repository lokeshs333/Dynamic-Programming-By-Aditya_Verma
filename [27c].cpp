// "minimum no. of deletion to make it a palindrome"
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(int n, int m, string a, string b){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0)dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    string a = "agbcba";
    string b=a;
    reverse(a.begin(),a.end());
    int n = a.size();
    int m = b.size();
    int ans = lcs(n, m, a, b);
    cout << "minimum no. of deletion to make it a palindrome = " <<a.size()-ans << endl;
    return 0;
}
